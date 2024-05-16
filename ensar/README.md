### Chapitre 1

#### Description du matériel pour les exercices pratiques

Dans les exercices pratiques du cours "Embedded Systems Engineering I", nous développerons des logiciels pour les microcontrôleurs. Nous utiliserons le microcontrôleur STM32F446RET6U de la série 32 bits du fabricant ST Microelectronics. Pour les exercices pratiques, nous utiliserons une carte d'évaluation nommée ST Nucleo F446RE. La figure 1.1 montre cette carte.

**Figure 1.1 : La carte d'évaluation ST Microelectronics Nucleo-F446RE**

Le microcontrôleur, qui est au centre de notre attention, se trouve au centre de la moitié inférieure de la carte (le grand boîtier noir sous l'étiquette avec le nom de la carte).

La plupart des connexions du microcontrôleur sont reliées aux bandes de broches situées à gauche et à droite, permettant ainsi d'utiliser le microcontrôleur de manière similaire à s'il était monté directement sur une carte pour un produit avec un système embarqué. C'est pourquoi on appelle cela une carte d'évaluation – elle permet de vérifier si une solution technique basée sur le microcontrôleur fonctionne dans la pratique. Si c'est le cas, on conçoit ensuite une carte de circuit imprimé qui utilise le microcontrôleur sans les composants supplémentaires de la carte d'évaluation.

Mais quels sont ces composants supplémentaires ? De nombreux composants sur cette carte facilitent l'utilisation du microcontrôleur :

1. **Dans la partie supérieure de la carte (séparée par des trous allongés) se trouve une interface qui permet de connecter le microcontrôleur à un port USB**. Les fonctions fournies sont :
   - **Alimentation électrique** : Le microcontrôleur peut être alimenté via le port USB en haut de la carte (couleur dorée). Cela évite de connecter une batterie supplémentaire sur la moitié inférieure de la carte, utilisant l'alimentation du PC connecté. Une banque d'alimentation USB peut également être utilisée.
   - **Programmation** : Le microcontrôleur doit être programmé et le programme doit être transféré sur le microcontrôleur. Le puce U2 sur la carte contient une interface qui communique avec l'ordinateur via USB. Lorsqu'un nouveau programme doit être transféré sur le microcontrôleur, cette interface arrête le microcontrôleur et transfère le nouveau programme sur la mémoire flash du microcontrôleur.
   - **Débogage** : Le programme transféré sur le microcontrôleur peut être incorrect. Lors du débogage, l'exécution du microcontrôleur peut être observée et manipulée pas à pas pour identifier les problèmes. Le programme de débogage s'exécute sur le PC utilisé pour le développement du programme. L'interface USB communique avec le microcontrôleur et contrôle les fonctionnalités de débogage.
   - **Interface série** : Il peut être utile que le microcontrôleur envoie certaines données au PC pour le débogage, comme des valeurs de mesure à vérifier. L'interface série permet de facilement envoyer des données du programme du microcontrôleur vers le PC et inversement, permettant de contrôler les fonctions de test du programme du microcontrôleur.
   - **Indicateur de statut de la connexion** : La LED LD1 s'allume ou clignote en rouge lorsqu'il y a une tension sur le port USB et en vert lorsque des données sont transférées vers ou depuis le PC connecté.

2. **Dans la partie inférieure de la carte, on trouve également des composants utiles** :
   - Un bouton de réinitialisation (noir) redémarre le programme du microcontrôleur, via une ligne de contrôle spéciale.
   - Le bouton bleu est connecté à un GPIO du microcontrôleur et peut être utilisé comme interface utilisateur simple pour le programme du microcontrôleur.
   - La LED LD3 (petite, verte) est également connectée à un GPIO du microcontrôleur et peut être utilisée pour afficher des informations.
   - Des régulateurs de tension, des limiteurs de courant et des condensateurs assurent une alimentation stable, évitant les problèmes de tension instable.
   - En bas à gauche, le petit boîtier (X2) est un cristal de quartz, un oscillateur précis utilisé par le microcontrôleur selon sa configuration. Le microcontrôleur peut utiliser deux oscillateurs différents pour différentes fonctions.

### 1.1 Contenu de la mallette pour les exercices pratiques

Le kit de matériel pour les exercices pratiques comprend plusieurs composants en plus de la carte microcontrôleur. La figure 1.2 montre la mallette en position fermée et ouverte.

**Figure 1.2 : La mallette de l'Embedded Systems Engineering I pour les exercices pratiques**

Le contenu de la mallette comprend :
1. La carte ST Nucleo F446RE
2. Un câble USB vers Mini-USB pour connecter la carte microcontrôleur à un PC (Linux, Windows, Mac)
3. Un "Multi Function Shield" (en bas à gauche dans la mallette ouverte), fournissant des LED, des boutons-poussoirs, un afficheur à 7 segments et un potentiomètre, connectable à la carte Nucleo via une broche.
4. Un câble spécial pour connecter un capteur de luminosité et un écran OLED à la carte microcontrôleur.
5. Un capteur de luminosité
6. Un écran OLED de 128x64 pixels

### 1.2 Conseils de manipulation

L'électronique est généralement sensible. Pour la protéger, veuillez suivre ces conseils :
- Ne touchez pas les soudures, même si elles ne contiennent plus de plomb. Manipulez les cartes par les bords.
- Évitez les décharges électrostatiques (ESD) en vous déchargeant en touchant un objet métallique avant de manipuler les composants.
- Évitez de porter des vêtements en laine lors de la manipulation des microcontrôleurs.
- Les composants sont dans des sacs antistatiques. Ne les sortez que lorsque vous en avez besoin.
- Manipulez les cartes par les bords et déposez-les sur des surfaces non conductrices, comme du bois brut ou du papier non graphite.

La plupart des composants ont une protection rudimentaire contre les décharges électrostatiques. Le capteur de luminosité, en particulier, n'a pas de protection indiquée dans sa fiche technique. Évitez de laisser les composants en contact avec des surfaces métalliques pour éviter les courts-circuits.

### 1.3 Que faire en cas de panne ?

En travaillant avec du matériel, il est toujours possible qu'un composant tombe en panne. Si cela vous arrive ou si vous constatez que des composants sont défectueux dès le départ, contactez votre tuteur lors d'une session de consultation ou d'exercice. Il vérifiera avec vous si le matériel est vraiment défectueux et, le cas échéant, vous pourrez obtenir un remplacement gratuitement, sauf en cas de non-respect évident des règles.

### Chapitre 3

#### Exercices

##### 3.1 Blankes Brett

Dans ce chapitre, nous découvrirons la carte microcontrôleur et pratiquerons la programmation de base des microcontrôleurs.

###### 3.1.1 Installer Platform.IO

Pour les exercices pratiques, nous programmerons les microcontrôleurs en langage C. Nous utiliserons Visual Studio Code ou VS Codium avec l'extension Platform.IO comme environnement de développement. Voici les étapes à suivre :

1. **Installer Visual Studio Code ou VS Codium** sur votre PC depuis les sites https://code.visualstudio.com/ ou https://vscodium.com. Installez ensuite l'extension Platform.IO.
2. **Créer un projet Platform.IO** en suivant les instructions sur https://stm32-base.org/guides/platformio.html, en choisissant la carte "ST Nucleo F446RE". Compilez et transférez le programme Blink sur la carte microcontrôleur pour faire clignoter la LED LD2 (verte).
3. **Exécuter le programme avec le débogueur** pas à pas, en utilisant des points d'arrêt pour vérifier le comportement du programme.

###### 3.1.2 Blinken - aber Schaltbar!

Pour cette tâche, n'utilisez ni GPIO_InitStruct ni la fonction HAL_GPIO_WritePin. Écrivez directement dans les registres, par exemple : `GPIOA->PUPDR = (1<<3) | 1;`.

**Tâche :**
1. Écrire un programme qui fait clignoter la LED à 5 Hz.
2. Le clignotement doit pouvoir être activé/désactivé avec le bouton B1 :
   - Une pression et relâchement du bouton arrête le clignotement et éteint la LED.
   - Une nouvelle pression et relâchement du bouton redémarre le clignotement.
   - L'activation et la désactivation peuvent être effectuées à volonté.

##### 3.2 Schilder, Leuchtmittel und Flexible Widerstände

Ce chapitre introduit l'utilisation de matériel supplémentaire couramment trouvé dans les systèmes embarqués, tels que :
- Afficheurs multi-segments
- Convertisseurs analogique-numérique
- Afficheurs multi-LED
- Boutons-poussoirs

Les tâches supposent que le Shield est connecté à la carte Nucleo.

###### 3.2.1 LED Lauflicht

**Tâche :**
1. Écrire un programme affichant une lumière de course sur les 4 LED du Shield.
2. Si des comportements étranges apparaissent, essayez de les comprendre. Décrire le

 comportement suffira si le programme fonctionne sur trois des quatre LED.
3. Votre programme ne doit pas inclure d'attente bloquante - la fonction main doit être une boucle infinie vide. Utilisez des timers et des interruptions pour changer les LED en fonction du temps.

###### 3.2.2 Schub & Register

**Tâche :**
1. Écrire un programme qui peut afficher des combinaisons de segments sur l'afficheur multi-segments.
2. Étendre le programme pour afficher des nombres hexadécimaux à quatre chiffres.
3. Organiser le programme pour réutiliser le code de l'afficheur multi-segments.
4. Utiliser le programme pour créer une calculatrice unaire avec les trois boutons du Shield, affichant le résultat sur l'afficheur multi-segments.
   - Un bouton incrémente le résultat de 1.
   - Un bouton décrémente le résultat de 1.
   - Un bouton réinitialise le résultat à 0.

###### 3.2.3 Analoge Werte, Digitale Anzeigen

**Tâche :**
1. Écrire un programme pour échantillonner la tension à la sortie du diviseur de tension VR-A0 sur le Shield.
2. Afficher la valeur mesurée sur l'afficheur multi-segments.
3. Mettre à l'échelle la valeur mesurée pour qu'elle corresponde approximativement à la tension en volts, avec des valeurs valides entre 0V et 3V.

##### 3.3 Es werde Licht, aber wie viel?

L'objectif de ce chapitre est de découvrir l'interface I2C et de faire fonctionner un capteur externe. Connectez le câble spécial au Shield et au capteur de luminosité.

###### 3.3.1 Einwohnermeldeamt

**Tâche :**
1. Écrire un programme pour vérifier quels appareils sont connectés au bus I2C.
2. Afficher les adresses des appareils trouvés via l'interface série ou sur l'afficheur à 10 segments.

###### 3.3.2 Cuantos Candelas?

**Tâche :**
1. Écrire un programme pour échantillonner le capteur de luminosité à une fréquence minimale de 5 Hz.
2. Construire un affichage en barre de LED pour visualiser la luminosité.
3. Utiliser la modulation de largeur d'impulsion (PWM) pour afficher différentes intensités lumineuses sur les LED en fonction du capteur de luminosité.

##### 3.4 Display-Anzeige

Dans ce dernier chapitre, nous combinerons toutes les compétences acquises. Tous les composants de la mallette doivent être connectés simultanément : Shield, câble spécial, capteur de luminosité, et écran OLED.

**Tâche :**
1. Écrire un programme pour contrôler l'écran OLED.
2. Tester le programme en affichant une fonction sinusoïdale.
3. Dessiner également un cercle sur l'écran OLED.

**Tâche supplémentaire :**
1. Écrire un programme déclenchant une interruption temporisée à 10 Hz.
2. Échantillonner les valeurs de luminosité dans la routine de service d'interruption.
3. Tracer un historique des mesures sur l'écran OLED.
4. Permettre la mise en pause de l'enregistrement des mesures en maintenant un bouton du Shield enfoncé.
5. Afficher la dernière valeur mesurée en dB sur l'afficheur multi-segments en appuyant sur un autre bouton.

### Annexes

#### A. Liens vers les fiches techniques et informations sur le matériel

1. **Microcontrôleur** : [Document officiel](https://www.st.com/en/microcontrollers-microprocessors/stm32f446re.html)
2. **Périphériques dans la mallette** :
   - [Schéma du Multi-Function Shield](https://www.electroschematics.com/wp-content/uploads/2018/10/2-Arduino-MF-Shield-Schematic.png)
   - [Fiche technique du registre à décalage sur le Multi-Function Shield](https://assets.nexperia.com/documents/data-sheet/74HC_HCT595.pdf)
   - [Fiche technique du capteur de luminosité](https://cdn-reichelt.de/documents/datenblatt/A300/SENSOR_BH1750.pdf)
   - [Fiche technique du contrôleur d'affichage](https://cdn-shop.adafruit.com/datasheets/SSD1306.pdf)

#### B. Possibilité d'acheter soi-même l'équipement pour les exercices pratiques

Liste de composants nécessaires pour acheter et utiliser l'équipement pour les exercices pratiques, avec des liens vers des exemples d'achats.

#### C. Détails / Pour référence

Liste des broches du F446RE et leur utilisation pour les composants du kit d'expérimentation.

#### D. Dépannage

Que faire si la carte émet un bip lors de la programmation. Explication des versions de firmware et comment revenir à une version antérieure si nécessaire.