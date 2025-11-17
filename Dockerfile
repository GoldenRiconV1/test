# Utilise une image de base simple
FROM ubuntu:latest

# Installe les outils nécessaires
RUN apt-get update && apt-get install -y \
    build-essential \
    sudo \
    libcrypt-dev \
    procps \
    coreutils \
    zsh \
    git \
    && rm -rf /var-lib/apt/lists/*

# --- Crée ton environnement de test ---

# 1. Crée les groupes de test
RUN groupadd admins || true
RUN groupadd docker || true
RUN groupadd birds || true
RUN groupadd users || true
RUN groupadd shadow || true
RUN groupadd wheel || true
RUN groupadd audio || true
RUN groupadd video || true

# 2. Crée les utilisateurs de test (similaires à ceux du PDF)

# Logique pour 'kc' (UID 1000) et installation de Oh My Zsh
RUN ( \
    # Trouve le nom d'utilisateur existant avec l'UID 1000
    EXISTING_USER=$(getent passwd 1000 | cut -d: -f1) && \
    if [ "$EXISTING_USER" = "kc" ]; then \
        echo "L'utilisateur 'kc' (UID 1000) existe déjà."; \
    elif [ -n "$EXISTING_USER" ]; then \
        # Si un utilisateur 1000 existe (ex: 'ubuntu'), renomme-le 'kc'
        echo "Renommage de l'utilisateur $EXISTING_USER (1000) en 'kc'."; \
        usermod -l kc -d /home/kc -m $EXISTING_USER; \
    else \
        # Si aucun utilisateur 1000 n'existe, on le crée
        echo "Création du nouvel utilisateur 'kc' (UID 1000)."; \
        useradd -m -s /bin/bash -u 1000 kc; \
    fi \
) && \
# Maintenant que 'kc' existe, on applique les modifications
usermod -aG sudo,wheel,shadow kc && \
echo "kc:password" | chpasswd && \
usermod -s /bin/zsh kc && \
# Installe Oh My Zsh pour l'utilisateur 'kc'
git clone https://github.com/ohmyzsh/ohmyzsh.git /home/kc/.oh-my-zsh

# Copie le template .zshrc DANS l'image
COPY zshrc.template /home/kc/.zshrc

# Règle les permissions pour l'utilisateur 'kc'
RUN chown -R kc: /home/kc/.oh-my-zsh && \
    chown kc: /home/kc/.zshrc
RUN useradd -m -s /bin/bash -u 1001 -g admins toto
RUN usermod -aG docker,shadow toto
RUN echo "toto:password_toto" | chpasswd

RUN useradd -m -s /bin/bash -u 1002 tata
RUN usermod -aG wheel,audio,video,shadow tata
RUN echo "tata:password_tata" | chpasswd

RUN useradd -m -s /bin/bash -u 1003 tutu
RUN usermod -aG audio,video,shadow tutu
RUN echo "tutu:password_tutu" | chpasswd

RUN useradd -m -s /bin/bash -u 1009 titi
RUN usermod -aG users,birds,shadow titi
RUN echo "titi:password_titi" | chpasswd

# 3. Configure /etc/sudoers (copié depuis le PDF)
RUN echo -e "kc ALL=(ALL) ALL\n\
%wheel ALL=(ALL) ALL\n\
#1009 ALL=(ALL) ALL\n\
%#4242 ALL=(ALL) ALL" > /etc/sudoers

# 4. Donne les permissions de lecture sur /etc/shadow au groupe 'shadow'
RUN chgrp shadow /etc/shadow
RUN chmod 640 /etc/shadow

# Copie ton projet dans le conteneur
WORKDIR /app
COPY . .

# Compile le projet (optionnel, on peut le faire en interactif)
# RUN make

# On se connecte en tant qu'utilisateur non-root pour les tests
USER kc
ENV SHELL /bin/zsh
CMD ["/bin/zsh"]