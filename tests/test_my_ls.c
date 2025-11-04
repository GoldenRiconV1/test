#include <criterion/criterion.h>
#include <criterion/logging.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

static char *read_file(const char *path) {
    FILE *f = fopen(path, "r");
    if (!f) return NULL;
    if (fseek(f, 0, SEEK_END) != 0) { fclose(f); return NULL; }
    long len = ftell(f);
    if (len < 0) { fclose(f); return NULL; }
    rewind(f);
    char *buf = malloc((size_t)len + 1);
    if (!buf) { fclose(f); return NULL; }
    size_t r = fread(buf, 1, (size_t)len, f);
    (void)r;
    buf[len] = '\0';
    fclose(f);
    return buf;
}

static void compare_ls_outputs(const char *args)
{
    /* Nettoyage des anciens fichiers */
    system("rm -f /tmp/ls_out.txt /tmp/my_out.txt");

    char cmd_ls[512];
    char cmd_my[512];

    /* --color=never pour éviter les séquences ANSI */
    snprintf(cmd_ls, sizeof(cmd_ls),
        "ls --color=never %s > /tmp/ls_out.txt 2>&1", args);
    /* ../my_ls car les tests sont lancés depuis tests/ */
    snprintf(cmd_my, sizeof(cmd_my),
        "./my_ls %s > /tmp/my_out.txt 2>&1", args);

    int ret_ls = system(cmd_ls);
    int ret_my = system(cmd_my);

    char *out_ls = read_file("/tmp/ls_out.txt");
    char *out_my = read_file("/tmp/my_out.txt");

    cr_assert_neq(out_ls, NULL, "ls output missing for '%s'", args);
    cr_assert_neq(out_my, NULL, "my_ls output missing for '%s'", args);

    int exit_ls = WEXITSTATUS(ret_ls);
    int exit_my = WEXITSTATUS(ret_my);

    cr_assert_eq(exit_my, exit_ls,
        "Exit codes differ for '%s' (ls=%d, my_ls=%d)",
        args, exit_ls, exit_my);

    cr_assert_str_eq(out_my, out_ls,
        "Output differs for '%s'\nmy_ls:\n%s\nls:\n%s",
        args, out_my, out_ls);

    free(out_ls);
    free(out_my);
}

/* ========================================================= */
/* ==================== TESTS DE BASE ======================= */
/* ========================================================= */

Test(my_ls, no_args)                { compare_ls_outputs(""); }
Test(my_ls, single_directory)       { compare_ls_outputs("."); }

/* ========================================================= */
/* ==================== TESTS DE FLAGS ====================== */
/* ========================================================= */

Test(my_ls, flag_a)                 { compare_ls_outputs("-a"); }
Test(my_ls, flag_l)                 { compare_ls_outputs("-l"); }
Test(my_ls, flag_t)                 { compare_ls_outputs("-t"); }
Test(my_ls, flag_d)                 { compare_ls_outputs("-d ."); }
Test(my_ls, flag_R)                 { compare_ls_outputs("-R"); }

/* ========================================================= */
/* ============= COMBINAISONS DE FLAGS ====================== */
/* ========================================================= */

Test(my_ls, flag_la)                { compare_ls_outputs("-la"); }
Test(my_ls, flag_lt)                { compare_ls_outputs("-lt"); }
Test(my_ls, flag_lR)                { compare_ls_outputs("-lR"); }
Test(my_ls, flag_aR)                { compare_ls_outputs("-aR"); }
Test(my_ls, flag_at)                { compare_ls_outputs("-at"); }
Test(my_ls, flag_Ra)                { compare_ls_outputs("-Ra"); }

/* ========================================================= */
/* ===================== TESTS FICHIERS ===================== */
/* ========================================================= */

Test(my_ls, single_file)            { compare_ls_outputs("Makefile"); }
Test(my_ls, multiple_files)         { compare_ls_outputs("Makefile tests/test_my_ls.c"); }
Test(my_ls, file_and_dir)           { compare_ls_outputs("Makefile src"); }
Test(my_ls, multiple_files_flags)   { compare_ls_outputs("-l Makefile tests"); }

/* ========================================================= */
/* ===================== TESTS D'ERREURS ==================== */
/* ========================================================= */

Test(my_ls, non_existing_file)      { compare_ls_outputs("does_not_exist"); }
Test(my_ls, mix_valid_invalid)      { compare_ls_outputs("Makefile unknown_dir"); }
Test(my_ls, directory_and_invalid)  { compare_ls_outputs(". wrong_path"); }

/* ========================================================= */
/* ================= TESTS RECURSIFS ======================== */
/* ========================================================= */

Test(my_ls, recursive_basic)        { compare_ls_outputs("-R src"); }
Test(my_ls, recursive_a)            { compare_ls_outputs("-Ra"); }
Test(my_ls, recursive_l)            { compare_ls_outputs("-Rl"); }
Test(my_ls, multiple_dirs)          { compare_ls_outputs("src tests"); }
Test(my_ls, multiple_dirs_R)        { compare_ls_outputs("-R src tests"); }