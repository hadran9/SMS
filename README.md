# School Management System With C And GTK3+

The project is mainly built with **french language** for french users, but you can change the source code to adapt it based on your own language.

The graphic interface has been built using ***Glade interface builder*** and has been implemented with the **C language**. So basically when we're creating an interface with Glade it saves it as an ***XML file***, and you have two main ways to implement the XML file, either calling the XML file directly from the ***C file*** in the `main` function using `gtk_builder_add_from_file`, or adding the XML to a ***C File*** as a string and calling the string from the ***GTK builder*** using the instruction `gtk_builder_add_from_string` (The way I did, And I prefer this way because if the interface is implemented as a string, that means the interface will be integrated and compiled with the program and makes the program movable in all the possible directories without any problems, but if the interface is called from the GTK builder as a file, we need to move it always with the program). I've inserted the Interface in the header file "<a href="https://github.com/hadran9/SMS/blob/main/Code%20Source/Projet%20de%20Fin%20d'annee/main.h" target="_blank"><strong>main.h</strong></a>".

The project is mainly focusing on **Windows** platform, so if you want to use it, you need to rebase some keywords and some libraries  like `windows.c` in the source code and replace some key functions like `remove()` and `rename()`.

You can see my name a lot in this project because it's just a graduation project and not a commercial project to sell.

To edit the graphical interface or the language of the program you need to go to the header file "<a href="https://github.com/hadran9/SMS/blob/main/Code%20Source/Projet%20de%20Fin%20d'annee/main.h" target="_blank"><strong>main.h</strong></a>" and try to change the string `HadranGui` and adapt the components according to your needs.

The program is totally portable in any folder, which means that you can work with the executable and move it any time without losing any of the old data, and I achieved that by designing the program to create a special workspace in the hard drive. The program have a four set of drives to check from `C:` to `F:` if the any of the drives exist the program continue it's work by creating a workspace(a root folder) to save his data, so when ever the program(the executable) has been moved from one folder to another he doesn't lose any data. The workspace is basically located in the first available drive found (from `C:` to `F:`) in the folder called `Programme` and the data located in the folder `Programme\Donnees` (Example: So once the program going to start for the first time, he will do a check of the vailable drives starting from the drive named `C:` if it exist it'll create the workspace there and the result will be `C:\Programme` and `C:\Programme\Donnees` if the drive named `C:` doesn't exist it'll move to next possible drive...).

The program requires the **GTK3+** library to be installed on the host machine, so I also created and "<a href="https://github.com/hadran9/SMS/blob/main/Installer/Installer%20de%20PFA%20D'Ayoub%20Hadran.exe" target="_blank"><strong><u>installer</u></strong></a>" which take cares of that, and it takes care also of uninstalling all the installed files. All of the **GTK+** necessary files are installed too in the workspace inside the folder `Programme\gtk`.

If you want only the executable you can find it directly in "<a href="https://github.com/hadran9/SMS/blob/main/Executable/Projet%20de%20Fin%20d'annee.exe" target="_blank"><strong><u>here</u></strong></a>", or if you want to go more in dept and try to debug the program using the "<a href="https://github.com/hadran9/SMS/blob/main/Code%20Source/Projet%20de%20Fin%20d'annee/bin/Debug/Projet%20de%20Fin%20d'annee.exe" target="_blank"><strong><u>debug version</u></strong></a>" you can go to the version who shows also the console and see if there's any error or warnings showing.

The program has been built using **GTK3+** and **C language** and **Code::Blocks** editor.

Click <a href="#pics"><strong>here</strong></a> to see the screenshots of the program.

# Système de Gestion Scolaire avec C et GTK3+

Le projet est principalement construit en **langue française** pour les utilisateurs français, mais vous pouvez changer le code source pour l'adapter en fonction de votre propre langue.

L'interface graphique a été construite à l'aide du ***générateur d'interface Glade*** et a été implémentée avec le **langage C**. Donc, fondamentalement, lorsque nous créons une interface avec Glade, elle l'enregistre sous forme de ***fichier XML***, et vous avez deux façons principales d'implémenter le fichier XML, soit en appelant le fichier XML directement à partir du ***fichier C*** dans la fonction `main` en utilisant `gtk_builder_add_from_file`, ou en ajoutant le fichier XML à l'intérieur d'un fichier C en tant qu'une chaîne de caractères et en appelant à la chaîne caractère depuis ***le générateur GTK*** en utilisant l'instruction `gtk_builder_add_from_string` (comme je l'ai fait, Et je préfère généralement cette façon parce que si l'interface est implémentée comme une chaîne de caractères, cela signifie que l'interface sera intégrée et compilée avec le programme et rendra le programme déplaçable dans tous les répertoires sans aucun problème, mais si l'interface est appelé depuis le générateur GTK sous forme de fichier, nous devons toujours le déplacer avec le programme). J'ai inséré l'interface dans le fichier d'en-tête "<a href="https://github.com/hadran9/SMS/blob/main/Code%20Source/Projet%20de%20Fin%20d'annee/main.h" target="_blank"><strong>main.h</strong></a>".

Le projet se concentre principalement sur la plate-forme **Windows**, donc si vous souhaitez l'utiliser, vous devez rebaser certains mots-clés et certaines bibliothèques comme `windows.c` dans le code source et remplacez certaines fonctions clés comme `remove()` et `rename()`.

Vous pouvez voir mon nom beaucoup de fois dans ce projet, car il ne s'agit que d'un projet de fin d'études et non d'un projet commercial à vendre.

Pour éditer l'interface graphique ou la langue du programme, vous devez aller dans le fichier d'en-tête "<a href="https://github.com/hadran9/SMS/blob/main/Code%20Source/Projet%20de%20Fin%20d'annee/main.h" target="_blank"><strong>main.h</strong></a>" et essayer de changer la chaîne de caractères `HadranGui` et adapter les composants selon vos besoins.

Le programme est totalement portable dans n'importe quel dossier, ce qui signifie que vous pouvez travailler avec l'exécutable et le déplacer à tout moment sans perdre les données existantes, et j'ai réalisé cela en concevant le programme pour créer un espace de travail spécial dans les disques durs. Le programme dispose de quatre ensembles de lecteurs pour vérifier de `C` à `F` si l'un des lecteurs existe, le programme continue son travail en créant un espace de travail (un dossier racine) pour enregistrer ses données, donc à chaque fois le programme (l'exécutable) est déplacé d'un dossier à un autre, il ne perd aucune donnée existant. L'espace de travail est essentiellement situé dans le premier lecteur disponible trouvé (de `C` à `F`) dans le dossier appelé `Program` et les données situées dans le dossier `Programme\Donnees` (Exemple: Donc une fois que le programme va démarrer pour la première fois, il va faire une vérification des lecteurs disponibles à partir du lecteur nommé `C:` s'il existe, il créera l'espace de travail là-bas et le résultat sera `C:\Programme` et `C:\Programme\Donnees` si le lecteur nommé `C:` n'existe pas, il passera au lecteur possible suivant ...).

Le programme nécessite que la bibliothèque GTK3+ soit installée sur la machine hôte, j'ai donc également créé un "<a href="https://github.com/hadran9/SMS/blob/main/Installer/Installer%20de%20PFA%20D'Ayoub%20Hadran.exe" target="_blank"><strong><u>Installer</u></strong></a>" qui s'en occupe de configurer ça, et il s'occupe également de désinstaller tous les fichiers installés par défaut. Tous les fichiers **GTK+** nécessaires sont également installés dans l'espace de travail dans le dossier `Programme\gtk`.

Si vous ne voulez que l'exécutable, vous pouvez le trouver directement "<a href="https://github.com/hadran9/SMS/blob/main/Executable/Projet%20de%20Fin%20d'annee.exe" target="_blank"><strong><u>ici</u></strong></a>", ou si vous voulez aller plus loin et essayer de déboguer le programme vous-même en utilisant la "<a href="https://github.com/hadran9/SMS/blob/main/Code%20Source/Projet%20de%20Fin%20d'annee/bin/Debug/Projet%20de%20Fin%20d'annee.exe" target="_blank"><strong><u>version de débogage</u></strong></a>" vous pouvez accéder à la version qui affiche également la console et voir s'il y a des erreurs ou des avertissements.

Le programme a été construit en utilisant  **GTK3+** et **le langage C** et l'éditeur de code **Code::Blocks**.

Cliquez <a href="#pics"><strong>ici</strong></a> pour voir les captures d'écran du programme.

<br id="pics" />

<p align="center"> 
<img src="https://github.com/hadran9/SMS/blob/main/Screenshots/Capture1.JPG">
</p>


<p align="center"> 
<img src="https://github.com/hadran9/SMS/blob/main/Screenshots/2.JPG">
</p>


<p align="center"> 
<img src="https://github.com/hadran9/SMS/blob/main/Screenshots/3.JPG">
</p>


<p align="center"> 
<img src="https://github.com/hadran9/SMS/blob/main/Screenshots/Capture4.JPG">
</p>


<p align="center"> 
<img src="https://github.com/hadran9/SMS/blob/main/Screenshots/Capture5.JPG">
</p>


<p align="center"> 
<img src="https://github.com/hadran9/SMS/blob/main/Screenshots/Capture6.JPG">
</p>


<p align="center"> 
<img src="https://github.com/hadran9/SMS/blob/main/Screenshots/Capture7.JPG">
</p>


<p align="center"> 
<img src="https://github.com/hadran9/SMS/blob/main/Screenshots/Capture8.JPG">
</p>


<p align="center"> 
<img src="https://github.com/hadran9/SMS/blob/main/Screenshots/Capture9.JPG">
</p>


<p align="center"> 
<img src="https://github.com/hadran9/SMS/blob/main/Screenshots/Capture10.JPG">
</p>


<p align="center"> 
<img src="https://github.com/hadran9/SMS/blob/main/Screenshots/Capture11.JPG">
</p>


<p align="center"> 
<img src="https://github.com/hadran9/SMS/blob/main/Screenshots/Capture12.JPG">
</p>


<p align="center"> 
<img src="https://github.com/hadran9/SMS/blob/main/Screenshots/Capture15.JPG">
</p>


<p align="center"> 
<img src="https://github.com/hadran9/SMS/blob/main/Screenshots/Capture16.JPG">
</p>


<p align="center"> 
<img src="https://github.com/hadran9/SMS/blob/main/Screenshots/Capture17.JPG">
</p>
