#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/stat.h>
#include <windows.h>
#include <gtk/gtk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

#include "main.h"


void CheckDSK()
{

    char DiskC[] = {"C:\\"};
    char DiskD[] = {"D:\\"};
    char DiskE[] = {"E:\\"};
    char DiskF[] = {"F:\\"};

    if(VerfierLeDossierDeTravail(DiskC))
    {
        strcpy(DossierPrincipale,"C:\\Programme");
        strcpy(DossierDeTravail,"C:\\Programme\\Donnees");
    }
    else
    {
        if(VerfierLeDossierDeTravail(DiskD))
        {
            strcpy(DossierPrincipale,"D:\\Programme");
            strcpy(DossierDeTravail,"D:\\Programme\\Donnees");
        }
        else
        {
            if(VerfierLeDossierDeTravail(DiskE))
            {
                strcpy(DossierPrincipale,"E:\\Programme");
                strcpy(DossierDeTravail,"E:\\Programme\\Donnees");
            }
            else
            {
                if(VerfierLeDossierDeTravail(DiskF))
                {
                    strcpy(DossierPrincipale,"F:\\Programme");
                    strcpy(DossierDeTravail,"F:\\Programme\\Donnees");
                }
                else
                {
                    exit(0);
                }
            }
        }
    }
}


void GetIdAndPass()
{

    char varGetID[MAXCHARS];

    strcpy(varGetID, DossierDeTravail);
    strcat(varGetID, "\\");
    strcat(varGetID, "Parametre.bin");

    FILE* GetID = NULL;

    GetID = fopen(varGetID,"rb");

    if (GetID != NULL)
    {

        fscanf(GetID, "ID: %d;\nPassEnabled: %d;\nMDP: %s\n", &IDFromFile, &PassEnabled, PassFromFile);

        fclose(GetID);

    }

    for (int i = 0; PassFromFile[i]!='\0'; i++)
    {
        if(PassFromFile[i] == Tiret)
        {
            PassFromFile[i] = Espace;
        }
    }

}

void CreateIdAndPass()
{

    char varGetID[MAXCHARS];

    strcpy(varGetID, DossierDeTravail);
    strcat(varGetID, "\\");
    strcat(varGetID, "Parametre.bin");

    FILE* CreateID = NULL;

    CreateID = fopen(varGetID,"wb");

    if (CreateID != NULL)
    {

        fprintf(CreateID, "ID: 0;\nPassEnabled: 0;\nMDP: Nothing\n");

        fclose(CreateID);

    }


}

void SetIDAndPass()
{

    char varGetID[MAXCHARS];

    strcpy(varGetID, DossierDeTravail);
    strcat(varGetID, "\\");
    strcat(varGetID, "Parametre.bin");

    FILE* SetID = NULL;

    SetID  = fopen(varGetID,"wb");

    if (SetID != NULL)
    {

        fprintf(SetID, "ID: %d;\nPassEnabled: %d;\nMDP: %s\n", IDFromFile, PassEnabled, PassFromFile);
        fclose(SetID);

    }

}

void PremiereLancementFunction()
{

    PremiereLancement = 1;
    CreerDossierDeTravail();
    CreateIdAndPass();

}

int VerfierLeDossierDeTravail(const char *chemin)
{
    struct stat stats;

    stat(chemin, &stats);

    if (S_ISDIR(stats.st_mode))
        return 1;

    return 0;
}


void CreerDossierDeTravail(void)
{

    mkdir(DossierPrincipale);
    mkdir(DossierDeTravail);

}

int ResultatDeVerificationDeDossier()
{

    if (VerfierLeDossierDeTravail(DossierDeTravail))
    {
        return 1;
    }
    else
    {
        return 2;
    }

}

void SauvegarderLesClassesVersArray()
{

    int i = 0;
    char FichierTXT[MAXCHARS];

    strcpy(FichierTXT, DossierDeTravail);
    strcat(FichierTXT, "\\Classes.txt");

    FILE *fichier = NULL;

    fichier = fopen(FichierTXT, "r");

    if (fichier != NULL)
    {

        while (i < MAXCHARS && fgets(FichierTXTversTableau[i], sizeof(FichierTXTversTableau[0]), fichier))
        {
            FichierTXTversTableau[i][strlen(FichierTXTversTableau[i])-1] = '\0';
            i = i + 1;
        }

        fclose(fichier);

    }

    TailleSize = i;

}

G_MODULE_EXPORT void on_window1_destroy()
{
    gtk_main_quit();
    if (ImageEH == 1)
    {
        g_object_unref (pixbuf);
        g_free(widgets);
    }

}

G_MODULE_EXPORT void on_window2_destroy()
{
    gtk_main_quit();
    if (ImageEH == 1)
    {
        g_object_unref (pixbuf);
        g_free(widgets);
    }
}
G_MODULE_EXPORT void on_window3_destroy()
{
    gtk_main_quit();
    if (ImageEH == 1)
    {
        g_object_unref (pixbuf);
        g_free(widgets);
    }
}

G_MODULE_EXPORT void on_window4_destroy()
{
    gtk_main_quit();
    if (ImageEH == 1)
    {
        g_object_unref (pixbuf);
        g_free(widgets);
    }
}

G_MODULE_EXPORT void on_window6_destroy()
{
    gtk_main_quit();
    if (ImageEH == 1)
    {
        g_object_unref (pixbuf);
        g_free(widgets);
    }
}

G_MODULE_EXPORT void on_window7_destroy()
{
    gtk_main_quit();
    if (ImageEH == 1)
    {
        g_object_unref (pixbuf);
        g_free(widgets);
    }
}

G_MODULE_EXPORT void on_window8_destroy()
{
    gtk_main_quit();
    if (ImageEH == 1)
    {
        g_object_unref (pixbuf);
        g_free(widgets);
    }
}


int main(int argc, char *argv[])
{

    char Emplacement[] = {"Accueil"}, CompileDate[MAXCHARS], CompileHeure[MAXCHARS];

    CheckDSK();

    if (ResultatDeVerificationDeDossier() == 1)
    {

        SauvegarderLesClassesVersArray();

    }
    else if(ResultatDeVerificationDeDossier() == 2)
    {
        PremiereLancementFunction();
    }

    GetIdAndPass();


    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_string (builder, HadranGui, -1, NULL);

    window1 = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));
    window2 = GTK_WIDGET(gtk_builder_get_object(builder, "window2"));
    window3 = GTK_WIDGET(gtk_builder_get_object(builder, "window3"));
    window4 = GTK_WIDGET(gtk_builder_get_object(builder, "window4"));
    window5 = GTK_WIDGET(gtk_builder_get_object(builder, "window5"));
    window6 = GTK_WIDGET(gtk_builder_get_object(builder, "window6"));
    window7 = GTK_WIDGET(gtk_builder_get_object(builder, "window7"));
    window8 = GTK_WIDGET(gtk_builder_get_object(builder, "window8"));
    gtk_builder_connect_signals(builder, NULL);

    fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));

    labeltitre = GTK_WIDGET(gtk_builder_get_object(builder, "label1"));
    ComboClasses = GTK_WIDGET(gtk_builder_get_object(builder, "ComboClasses"));
    ComboEleves = GTK_WIDGET(gtk_builder_get_object(builder, "ComboEleves"));
    frame1 = GTK_WIDGET(gtk_builder_get_object(builder, "frame1"));
    lblID = GTK_WIDGET(gtk_builder_get_object(builder, "lblID"));
    lblNom = GTK_WIDGET(gtk_builder_get_object(builder, "lblNom"));
    lblPrenom = GTK_WIDGET(gtk_builder_get_object(builder, "lblPrenom"));
    lblDateNaissance = GTK_WIDGET(gtk_builder_get_object(builder, "lblDateNaissance"));
    lblNationalite = GTK_WIDGET(gtk_builder_get_object(builder, "lblNationalite"));
    lblSexe = GTK_WIDGET(gtk_builder_get_object(builder, "lblSexe"));
    lblClasse = GTK_WIDGET(gtk_builder_get_object(builder, "lblClasse"));
    lblGroupe = GTK_WIDGET(gtk_builder_get_object(builder, "lblGroupe"));
    btnAjouterEleve = GTK_WIDGET(gtk_builder_get_object(builder, "btnAjouterEleve"));
    btnAjouterOfficielle = GTK_WIDGET(gtk_builder_get_object(builder, "btnAjouterOfficielle"));
    btnQuitter1 = GTK_WIDGET(gtk_builder_get_object(builder, "btnQuitter1"));
    btnRetour2 = GTK_WIDGET(gtk_builder_get_object(builder, "btnRetour2"));
    btnQuitter2 = GTK_WIDGET(gtk_builder_get_object(builder, "btnQuitter2"));
    ComboAddStudentInClass = GTK_WIDGET(gtk_builder_get_object(builder, "ComboAddStudentInClass"));
    aspectframe1 = GTK_WIDGET(gtk_builder_get_object(builder, "aspectframe1"));
    ImageEleve = GTK_WIDGET(gtk_builder_get_object(builder, "ImageEleve"));
    EntreeNom = GTK_WIDGET(gtk_builder_get_object(builder, "EntreeNom"));
    EntreePrenom = GTK_WIDGET(gtk_builder_get_object(builder, "EntreePrenom"));
    EntreeGroupe = GTK_WIDGET(gtk_builder_get_object(builder, "EntreeGroupe"));
    EntreeNationalite = GTK_WIDGET(gtk_builder_get_object(builder, "EntreeNationalite"));
    EntreeDate = GTK_WIDGET(gtk_builder_get_object(builder, "EntreeDate"));
    ComboAddSexe = GTK_WIDGET(gtk_builder_get_object(builder, "ComboAddSexe"));
    label14 = GTK_WIDGET(gtk_builder_get_object(builder, "label14"));
    SwitchImage = GTK_WIDGET(gtk_builder_get_object(builder, "SwitchImage"));
    SwitchModifierImage = GTK_WIDGET(gtk_builder_get_object(builder, "SwitchModifierImage"));
    frameImage = GTK_WIDGET(gtk_builder_get_object(builder, "frameImage"));
    FrameModifierImage = GTK_WIDGET(gtk_builder_get_object(builder, "FrameModifierImage"));
    lblGroupeCreation = GTK_WIDGET(gtk_builder_get_object(builder, "lblGroupeCreation"));
    Parcourir = GTK_WIDGET(gtk_builder_get_object(builder, "Parcourir"));
    ParcourirNouvelleImage = GTK_WIDGET(gtk_builder_get_object(builder, "ParcourirNouvelleImage"));
    calendar1 = GTK_WIDGET(gtk_builder_get_object(builder, "calendar1"));
    calendar2 = GTK_WIDGET(gtk_builder_get_object(builder, "calendar2"));
    btnModifier = GTK_WIDGET(gtk_builder_get_object(builder, "btnModifier"));
    btnSupprimer = GTK_WIDGET(gtk_builder_get_object(builder, "btnSupprimer"));
    ComboModifierClasse = GTK_WIDGET(gtk_builder_get_object(builder, "ComboModifierClasse"));
    EntreeModifierNom = GTK_WIDGET(gtk_builder_get_object(builder, "EntreeModifierNom"));
    EntreeModifierPrenom = GTK_WIDGET(gtk_builder_get_object(builder, "EntreeModifierPrenom"));
    EntreeModifierDate = GTK_WIDGET(gtk_builder_get_object(builder, "EntreeModifierDate"));
    ComboModifierSex = GTK_WIDGET(gtk_builder_get_object(builder, "ComboModifierSex"));
    EntreeModifierNationalite = GTK_WIDGET(gtk_builder_get_object(builder, "EntreeModifierNationalite"));
    EntreeModifierGroupe = GTK_WIDGET(gtk_builder_get_object(builder, "EntreeModifierGroupe"));
    switchImageExiste = GTK_WIDGET(gtk_builder_get_object(builder, "switchImageExiste"));
    label35 = GTK_WIDGET(gtk_builder_get_object(builder, "label35"));
    BtnQuitter3 = GTK_WIDGET(gtk_builder_get_object(builder, "BtnQuitter3"));
    BtnRetour3 = GTK_WIDGET(gtk_builder_get_object(builder, "BtnRetour3"));
    RadioAjouter = GTK_WIDGET(gtk_builder_get_object(builder, "RadioAjouter"));
    frame2 = GTK_WIDGET(gtk_builder_get_object(builder, "frame2"));
    entryAjouterClasse = GTK_WIDGET(gtk_builder_get_object(builder, "entryAjouterClasse"));
    label43 = GTK_WIDGET(gtk_builder_get_object(builder, "label43"));
    label43 = GTK_WIDGET(gtk_builder_get_object(builder, "label43"));
    RadioModifier = GTK_WIDGET(gtk_builder_get_object(builder, "RadioModifier"));
    entryModifierClasse = GTK_WIDGET(gtk_builder_get_object(builder, "entryModifierClasse"));
    comboModifier = GTK_WIDGET(gtk_builder_get_object(builder, "comboModifier"));
    label46 = GTK_WIDGET(gtk_builder_get_object(builder, "label46"));
    label47 = GTK_WIDGET(gtk_builder_get_object(builder, "label47"));
    frame3 = GTK_WIDGET(gtk_builder_get_object(builder, "frame3"));
    RadioSupprimer = GTK_WIDGET(gtk_builder_get_object(builder, "RadioSupprimer"));
    frame4 = GTK_WIDGET(gtk_builder_get_object(builder, "frame4"));
    comboSupprimer = GTK_WIDGET(gtk_builder_get_object(builder, "comboSupprimer"));
    buttonQuitter4 = GTK_WIDGET(gtk_builder_get_object(builder, "buttonQuitter4"));
    buttonSaveGererClasse = GTK_WIDGET(gtk_builder_get_object(builder, "buttonSaveGererClasse"));
    pbar1 = GTK_WIDGET(gtk_builder_get_object(builder, "pbar1"));
    BtnApropos = GTK_WIDGET(gtk_builder_get_object(builder, "BtnApropos"));
    buttonContinuer6 = GTK_WIDGET(gtk_builder_get_object(builder, "buttonContinuer6"));
    buttonQuitter6 = GTK_WIDGET(gtk_builder_get_object(builder, "buttonQuitter6"));
    entryPass = GTK_WIDGET(gtk_builder_get_object(builder, "entryPass"));
    buttonRetour7 = GTK_WIDGET(gtk_builder_get_object(builder, "buttonRetour7"));
    label62 = GTK_WIDGET(gtk_builder_get_object(builder, "label62"));
    switchAppLock = GTK_WIDGET(gtk_builder_get_object(builder, "switchAppLock"));
    BtnParametre = GTK_WIDGET(gtk_builder_get_object(builder, "BtnParametre"));
    buttonAfficherPass = GTK_WIDGET(gtk_builder_get_object(builder, "buttonAfficherPass"));
    buttonAffihcerPassEntrer = GTK_WIDGET(gtk_builder_get_object(builder, "buttonAffihcerPassEntrer"));
    entryPassActuelle = GTK_WIDGET(gtk_builder_get_object(builder, "entryPassActuelle"));
    entryNouveauPass = GTK_WIDGET(gtk_builder_get_object(builder, "entryNouveauPass"));
    entryConfirmerPass = GTK_WIDGET(gtk_builder_get_object(builder, "entryConfirmerPass"));
    label77 = GTK_WIDGET(gtk_builder_get_object(builder, "label77"));
    buttonEnregistrerPass = GTK_WIDGET(gtk_builder_get_object(builder, "buttonEnregistrerPass"));
    buttonRetourPass = GTK_WIDGET(gtk_builder_get_object(builder, "buttonRetourPass"));
    buttonAffihcerPassEntrer = GTK_WIDGET(gtk_builder_get_object(builder, "buttonAffihcerPassEntrer"));


    filter = gtk_file_filter_new();
    gtk_file_filter_set_name(filter, (const gchar*) "Images Seulement");
    gtk_file_filter_add_mime_type(filter, (const gchar*) "image/png");
    gtk_file_filter_add_mime_type(filter, (const gchar*) "image/jpeg");
    gtk_file_filter_add_mime_type(filter, (const gchar*) "image/bmp");
    gtk_file_filter_add_pattern(filter, (const gchar*) "*.png");
    gtk_file_filter_add_pattern(filter, (const gchar*) "*.jpg");
    gtk_file_filter_add_pattern(filter, (const gchar*) "*.bmp");
    gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(Parcourir), filter);


    filter2 = gtk_file_filter_new();
    gtk_file_filter_set_name(filter2, (const gchar*) "Images Seulement");
    gtk_file_filter_add_mime_type(filter2, (const gchar*) "image/png");
    gtk_file_filter_add_mime_type(filter2, (const gchar*) "image/jpeg");
    gtk_file_filter_add_mime_type(filter2, (const gchar*) "image/bmp");
    gtk_file_filter_add_pattern(filter2, (const gchar*) "*.png");
    gtk_file_filter_add_pattern(filter2, (const gchar*) "*.jpg");
    gtk_file_filter_add_pattern(filter2, (const gchar*) "*.bmp");
    gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(ParcourirNouvelleImage), filter2);


    gtk_widget_hide(aspectframe1);
    gtk_widget_hide(frame1);
    DonneesEleveToLabel();
    gtk_widget_hide(calendar1);
    gtk_widget_hide(calendar2);
    gtk_widget_hide(label35);
    gtk_widget_hide(SwitchModifierImage);


    gtk_switch_set_active(GTK_SWITCH (SwitchImage), FALSE);
    gtk_widget_hide(frameImage);
    ImageActive = 0;

    gtk_switch_set_active(GTK_SWITCH (SwitchModifierImage), FALSE);
    gtk_switch_set_active(GTK_SWITCH (switchImageExiste), FALSE);
    gtk_widget_hide(FrameModifierImage);
    ModifierImageActive = 0;

    if(PassEnabled == 0)
    {
        gtk_switch_set_active(GTK_SWITCH(switchAppLock), (gboolean) FALSE);
    }
    else if (PassEnabled == 1)
    {
        gtk_switch_set_active(GTK_SWITCH(switchAppLock), (gboolean) TRUE);
    }

    gtk_widget_hide(frame2);
    gtk_widget_hide(frame3);
    gtk_widget_hide(frame4);


    sprintf(CompileDate,"Le %s ", __DATE__);
    sprintf(CompileHeure,"%s", __TIME__);

    strcat(CompileDate,CompileHeure);

    gtk_label_set_text(GTK_LABEL(label62),(const gchar*) CompileDate);


    RemplissageListDesClasses(Emplacement);

    //GdkColor color;
    //if (gdk_color_parse("#ffffff", &color)) {
    //  gtk_widget_modify_bg(window5, GTK_STATE_NORMAL, &color);
    // }

    g_signal_connect (GTK_SWITCH (SwitchImage),"notify::active", G_CALLBACK (activate_SwitchImage), window2);
    g_signal_connect (GTK_SWITCH (SwitchModifierImage),"notify::active", G_CALLBACK (activate_SwitchModifierImage), window3);
    g_signal_connect (GTK_SWITCH (switchImageExiste),"notify::active", G_CALLBACK (activate_switchImageExiste), window3);
    g_signal_connect (GTK_SWITCH (switchAppLock),"notify::active", G_CALLBACK (activate_switchAppLock), window1);

    g_object_unref(builder);
    gtk_widget_show(window5);

    gtk_main();

    return EXIT_SUCCESS;
}

void RemplissageListDesClasses(char *PEmplacement)
{

    SauvegarderLesClassesVersArray();

    char Emplacement[MAXCHARS], TempClasse[MAXCHARS];

    strcpy(Emplacement,PEmplacement);

    if (strcmp("Accueil",Emplacement)==0)
    {

        gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(ComboClasses));

        for(int i=0; i<TailleSize; i++)
        {
            strcpy(TempClasse, FichierTXTversTableau[i]);

            for (int j = 0; TempClasse[j]!='\0'; j++)
            {
                if(TempClasse[j] == Tiret)
                {
                    TempClasse[j] = Espace;
                }
            }

            gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(ComboClasses), NULL, TempClasse);
        }

        gtk_combo_box_set_active(GTK_COMBO_BOX(ComboClasses), 0);

    }
    else if(strcmp("Ajouter",Emplacement) == 0)
    {

        gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(ComboAddStudentInClass));

        for(int i=0; i<TailleSize; i++)
        {
            strcpy(TempClasse, FichierTXTversTableau[i]);

            for (int j = 0; TempClasse[j]!='\0'; j++)
            {
                if(TempClasse[j] == Tiret)
                {
                    TempClasse[j] = Espace;
                }
            }

            gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(ComboAddStudentInClass), NULL, TempClasse);
        }

        gtk_combo_box_set_active(GTK_COMBO_BOX(ComboAddStudentInClass), 0);

    }
    else if(strcmp("Modifier",Emplacement) == 0)
    {

        for(int i=0; i<TailleSize; i++)
        {
            strcpy(TempClasse, FichierTXTversTableau[i]);

            for (int j = 0; TempClasse[j]!='\0'; j++)
            {
                if(TempClasse[j] == Tiret)
                {
                    TempClasse[j] = Espace;
                }
            }
            if(strcmp(UnchagedClasse,TempClasse) != 0)
            {
                gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(ComboModifierClasse), NULL, TempClasse);
            }
        }

    }
    else if(strcmp("Gerer-Modifier",Emplacement) == 0)
    {

        gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(comboModifier));

        for(int i=0; i<TailleSize; i++)
        {
            strcpy(TempClasse, FichierTXTversTableau[i]);

            for (int j = 0; TempClasse[j]!='\0'; j++)
            {
                if(TempClasse[j] == Tiret)
                {
                    TempClasse[j] = Espace;
                }
            }
            if(strcmp(UnchagedClasse,TempClasse) != 0)
            {
                gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(comboModifier), NULL, TempClasse);
            }
        }

    }
    else if(strcmp("Gerer-Supprimer",Emplacement) == 0)
    {

        gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(comboSupprimer));

        for(int i=0; i<TailleSize; i++)
        {
            strcpy(TempClasse, FichierTXTversTableau[i]);

            for (int j = 0; TempClasse[j]!='\0'; j++)
            {
                if(TempClasse[j] == Tiret)
                {
                    TempClasse[j] = Espace;
                }
            }
            if(strcmp(UnchagedClasse,TempClasse) != 0)
            {
                gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(comboSupprimer), NULL, TempClasse);
            }
        }

    }

}

G_MODULE_EXPORT void on_ComboClasses_changed(GtkComboBox *c)
{
    gchar *item_text = 0;

    item_text = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(ComboClasses));

    if(item_text != NULL)
    {

        RemplissageListDesEleves();
    }

}

void RemplissageListDesEleves()
{

    char Donnees[MAXCHARS], Chaine[MAXCHARS];

    strcpy(Donnees,DossierDeTravail);
    strcat(Donnees,"\\");

    gchar *item_text = 0;

    item_text = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(ComboClasses));

    for (int i = 0; item_text[i]!='\0'; i++)
    {
        if(item_text[i] == Espace)
        {
            item_text[i] = Tiret;
        }
    }

    for (int i = 0; item_text[i]!='\0'; i++)
    {

        if(item_text[i] >= 'a' && item_text[i] <= 'z')
        {

            item_text[i] = item_text[i] - 32;

        }
    }

    strcat(Donnees,item_text);
    strcat(Donnees,"\\eleves.txt");


    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(ComboEleves));

    FILE* fichier = NULL;

    fichier = fopen(Donnees,"r");

    if (fichier != NULL)
    {
        while(fgets(Chaine,1000,fichier) != NULL)
        {

            for (int i = 0; Chaine[i]!='\0'; i++)
            {

                if(Chaine[i] == Tiret)
                {
                    Chaine[i] = Espace;
                }
            }

            SupprimerLigneVide(Chaine);

            gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(ComboEleves), NULL, Chaine);

        }

        fclose(fichier);
    }

}


G_MODULE_EXPORT void on_ComboEleves_changed(GtkComboBox *c)
{
    char Emplacement[] = {"Accueil"};

    RemplissageDonneesEleves(Emplacement);

}

void RemplissageDonneesEleves(char* EmplacementTmp)
{

    char EleveTXT[MAXCHARS], EleveImage[MAXCHARS], Emplacement[MAXCHARS];

    strcpy(Emplacement,EmplacementTmp);

    strcpy(EleveTXT, DossierDeTravail);
    strcpy(EleveImage, DossierDeTravail);
    strcat(EleveTXT,"\\");
    strcat(EleveImage,"\\");

    char ID[MAXCHARS],DateNaissanceAnnee[MAXCHARS],DateNaissanceMois[MAXCHARS],DateNaissanceJour[MAXCHARS];
    gchar *NomEleve = 0;
    gchar *NomClass = 0;

    NomClass = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(ComboClasses));
    NomEleve = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(ComboEleves));

    for (int i = 0; NomClass[i]!='\0'; i++)
    {
        if(NomClass[i] == Espace)
        {
            NomClass[i] = Tiret;
        }
    }

    for (int i = 0; NomClass[i]!='\0'; i++)
    {

        if(NomClass[i] >= 'a' && NomClass[i] <= 'z')
        {

            NomClass[i] = NomClass[i] - 32;

        }
    }

    if (NomEleve != NULL)
    {

        for (int i = 0; NomEleve[i]!='\0'; i++)
        {
            if(NomEleve[i] == Espace )
            {
                NomEleve[i] = Tiret;
            }
        }

        for (int i = 0; NomEleve[i]!='\0'; i++)
        {

            if(NomEleve[i] >= 'a' && NomEleve[i] <= 'z')
            {

                NomEleve[i] = NomEleve[i] - 32;

            }
        }

        strcat(EleveTXT,NomClass);

        strcat(EleveTXT,"\\");

        strcat(EleveTXT,NomEleve);

        SupprimerLigneVide(EleveTXT);

        strcat(EleveTXT,".txt");


        FILE* fichier = NULL;

        fichier = fopen(EleveTXT,"r");

        if (fichier != NULL)
        {


            while(fscanf(fichier,"ID: %d\nNom: %s\nPrenom: %s\nDate De Naissance: %d-%d-%d\nNationalite: %s\nSex: %d\nGroupe: %s\nImage: %s\nExtension: %s", &ElevesaAfficher.ID, ElevesaAfficher.Nom, ElevesaAfficher.Prenom, &ElevesaAfficher.DateNaissanceAnnee, &ElevesaAfficher.DateNaissanceMois, &ElevesaAfficher.DateNaissanceJour, ElevesaAfficher.Nationalite, &ElevesaAfficher.Sexe, ElevesaAfficher.Groupe, ElevesaAfficher.Image, ElevesaAfficher.Extension) == 11)
            {
            }

            for (int i = 0; ElevesaAfficher.Nom[i]!='\0'; i++)
            {
                if(ElevesaAfficher.Nom[i] == Tiret)
                {
                    ElevesaAfficher.Nom[i] = Espace;
                }
            }

            for (int i = 0; ElevesaAfficher.Prenom[i]!='\0'; i++)
            {
                if(ElevesaAfficher.Prenom[i] == Tiret)
                {
                    ElevesaAfficher.Prenom[i] = Espace;
                }
            }

            for (int i = 0; ElevesaAfficher.Groupe[i]!='\0'; i++)
            {
                if(ElevesaAfficher.Groupe[i] == Tiret)
                {
                    ElevesaAfficher.Groupe[i] = Espace;
                }
            }


            for (int i = 0; ElevesaAfficher.Nationalite[i]!='\0'; i++)
            {
                if(ElevesaAfficher.Nationalite[i] == Tiret)
                {
                    ElevesaAfficher.Nationalite[i] = Espace;
                }
            }


            sprintf(ID, "%d", ElevesaAfficher.ID);
            sprintf(DateNaissanceAnnee, "%d", ElevesaAfficher.DateNaissanceAnnee);
            sprintf(DateNaissanceMois, "%d", ElevesaAfficher.DateNaissanceMois);
            sprintf(DateNaissanceJour, "%d", ElevesaAfficher.DateNaissanceJour);

            strcat(DateNaissanceAnnee,"-");
            strcat(DateNaissanceAnnee,DateNaissanceMois);
            strcat(DateNaissanceAnnee,"-");
            strcat(DateNaissanceAnnee,DateNaissanceJour);

            strcpy(DateSauvegrader2, DateNaissanceAnnee);

            char Sexe[MAXCHARS];

            if (ElevesaAfficher.Sexe == 0)
            {
                strcpy(Sexe,"Homme");
            }
            else if(ElevesaAfficher.Sexe == 1)
            {
                strcpy(Sexe,"Femme");
            }

            if (strcmp(Emplacement,"Accueil")==0)
            {

                gtk_widget_show(frame1);
                gtk_widget_show(aspectframe1);

                gtk_label_set_text(GTK_LABEL(lblID), ID);
                gtk_label_set_text(GTK_LABEL(lblNom), ElevesaAfficher.Nom);
                gtk_label_set_text(GTK_LABEL(lblPrenom), ElevesaAfficher.Prenom);
                gtk_label_set_text(GTK_LABEL(lblDateNaissance), DateNaissanceAnnee);
                gtk_label_set_text(GTK_LABEL(lblNationalite), ElevesaAfficher.Nationalite);
                gtk_label_set_text(GTK_LABEL(lblSexe), Sexe);
                gtk_label_set_text(GTK_LABEL(lblClasse), NomClass);
                gtk_label_set_text(GTK_LABEL(lblGroupe),  ElevesaAfficher.Groupe);



                if(strcmp(ElevesaAfficher.Image,"Oui") == 0 )
                {

                    strcat(EleveImage,NomClass);

                    strcat(EleveImage,"\\");

                    strcat(EleveImage,NomEleve);

                    SupprimerLigneVide(EleveImage);

                    strcat(EleveImage,".");

                    strcat(EleveImage,ElevesaAfficher.Extension);

                    pixbuf = gdk_pixbuf_new_from_file_utf8(EleveImage, NULL);

                    if (pixbuf != NULL)
                    {
                        gtk_widget_show(aspectframe1);
                        widgets = g_new0(ResizeWidgets, 1);
                        widgets->image = ImageEleve;
                        widgets->pixbuf = pixbuf;


                        gtk_widget_set_size_request (GTK_WIDGET(ImageEleve), 20, 20);
                        pixbuf = gdk_pixbuf_scale_simple(pixbuf,100,100,GDK_INTERP_BILINEAR);
                        gtk_image_set_from_pixbuf(GTK_IMAGE(ImageEleve), pixbuf);
                        ImageEH = 1;

                    }
                    else if (pixbuf == NULL)
                    {
                        gtk_widget_hide(aspectframe1);
                        GtkWidget *pErreur;
                        pErreur = gtk_message_dialog_new (GTK_WINDOW(window1),
                                                          GTK_DIALOG_MODAL,
                                                          GTK_MESSAGE_ERROR,
                                                          GTK_BUTTONS_OK,
                                                          "Problem Lors Le Chargement De L'image");

                        gtk_dialog_run(GTK_DIALOG(pErreur));

                        gtk_widget_destroy(pErreur);
                    }
                }
                else
                {
                    gtk_widget_hide(aspectframe1);
                }
            }
            else if (strcmp(Emplacement,"Modifier")==0)
            {
                IDnonUpdated = ElevesaAfficher.ID;
                gtk_entry_set_text(GTK_ENTRY(EntreeModifierNom), ElevesaAfficher.Nom);
                gtk_entry_set_text(GTK_ENTRY(EntreeModifierPrenom), ElevesaAfficher.Prenom);
                gtk_entry_set_text(GTK_ENTRY(EntreeModifierDate), DateNaissanceAnnee);
                gtk_entry_set_text(GTK_ENTRY(EntreeModifierNationalite), ElevesaAfficher.Nationalite);
                gtk_entry_set_text(GTK_ENTRY(EntreeModifierGroupe),  ElevesaAfficher.Groupe);
                gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(ComboModifierClasse),(const gchar*) UnchagedClasse);
                gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(ComboModifierSex),(const gchar*) Sexe);

                gtk_combo_box_set_active(GTK_COMBO_BOX(ComboModifierSex), 0);
                gtk_combo_box_set_active(GTK_COMBO_BOX(ComboModifierClasse), 0);

                if (strcmp(Sexe,"Homme") == 0)
                {
                    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(ComboModifierSex), NULL,(const gchar*) "Femme");
                }
                else if(strcmp(Sexe,"Femme") == 0)
                {
                    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(ComboModifierSex), NULL,(const gchar*) "Homme");
                }
                else
                {
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(ComboModifierSex));
                    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(ComboModifierSex), NULL,(const gchar*) "Femme");
                    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(ComboModifierSex), NULL,(const gchar*) "Homme");
                }

                if(strcmp(ElevesaAfficher.Image,"Oui") == 0 )
                {

                    gtk_switch_set_active(GTK_SWITCH (switchImageExiste), TRUE);
                    StatusImage = 1;

                }
                else
                {

                    gtk_switch_set_active(GTK_SWITCH (switchImageExiste), FALSE);
                    StatusImage = 0;
                }

            }

            fclose(fichier);

        }
        else
        {

            gchar* sUtf8 = 0;
            gchar* bUtf8 = 0;

            bUtf8 = g_locale_from_utf8("Données d'élève Introuvable! ", -1, NULL, NULL, NULL);

            sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);


            DonneesEleveToLabel();
            gtk_widget_hide(aspectframe1);
            gtk_widget_hide(frame1);

            GtkWidget *pErreur;
            pErreur = gtk_message_dialog_new (GTK_WINDOW(window1),
                                              GTK_DIALOG_MODAL,
                                              GTK_MESSAGE_ERROR,
                                              GTK_BUTTONS_OK,
                                              sUtf8);

            gtk_dialog_run(GTK_DIALOG(pErreur));

            gtk_widget_destroy(pErreur);

            g_free(bUtf8);
            g_free(sUtf8);

        }

    }
    else
    {
        gtk_widget_hide(aspectframe1);
        gtk_widget_hide(frame1);
        DonneesEleveToLabel();
    }
}

void SupprimerLigneVide(char *str)
{
    int i;
    int Debut = 0;
    int Fin = strlen(str) - 1;

    while (isspace((unsigned char) str[Debut]))
        Debut++;

    while ((Fin >= Debut) && isspace((unsigned char) str[Fin]))
        Fin--;

    for (i = Debut; i <= Fin; i++)
        str[i - Debut] = str[i];

    str[i - Debut] = '\0';

}

G_MODULE_EXPORT void on_btnAjouterEleve_clicked(GtkButton *b)
{

    char Emplacement[]= {"Ajouter"};

    const gchar *TexteComboClasse;

    TexteComboClasse = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(ComboClasses));

    if(TexteComboClasse == NULL)
    {

        GtkWidget *pErreur;

        gchar* sUtf8 = 0;
        gchar* bUtf8 = 0;

        bUtf8 = g_locale_from_utf8(" S'il veut plaît Ajouter une Classe d'abord ! ", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);

        pErreur = gtk_message_dialog_new (GTK_WINDOW(window1),
                                          GTK_DIALOG_MODAL,
                                          GTK_MESSAGE_ERROR,
                                          GTK_BUTTONS_OK,
                                          sUtf8);

        gtk_dialog_run(GTK_DIALOG(pErreur));

        gtk_widget_destroy(pErreur);

        g_free(bUtf8);
        g_free(sUtf8);

    }
    else
    {

        RemplissageListDesClasses(Emplacement);
        Clear_Add_Student();
        gtk_widget_hide(frame1);
        gtk_widget_hide(aspectframe1);
        gtk_widget_hide(window1);
        gtk_widget_show(window2);

    }


}


G_MODULE_EXPORT void on_btnQuitter1_clicked(GtkButton *b)
{

    GtkWidget *pQuitter;

    pQuitter = gtk_message_dialog_new (GTK_WINDOW(window1),
                                       GTK_DIALOG_MODAL,
                                       GTK_MESSAGE_QUESTION,
                                       GTK_BUTTONS_YES_NO,
                                       "Voulez-vous vraiment\nquitter le programme?");

    switch(gtk_dialog_run(GTK_DIALOG(pQuitter)))
    {
    case GTK_RESPONSE_YES:
        gtk_main_quit();
        break;
    case GTK_RESPONSE_NO:
        gtk_widget_destroy(pQuitter);
        break;
    }

}

G_MODULE_EXPORT void on_btnRetour2_clicked(GtkButton *b)
{

    char Emplacement [] = {"Accueil"};

    const gchar *TextEntreeNom;
    const gchar *TextEntreePrenom;
    const gchar *TextEntreeDateNaissance;
    const gchar *TextEntreeGroupe;

    TextEntreeNom = gtk_entry_get_text(GTK_ENTRY(EntreeNom));
    TextEntreePrenom = gtk_entry_get_text(GTK_ENTRY(EntreePrenom));
    TextEntreeDateNaissance = gtk_entry_get_text(GTK_ENTRY(EntreeDate));
    TextEntreeGroupe = gtk_entry_get_text(GTK_ENTRY(EntreeGroupe));

    if (strcmp(TextEntreeNom,"")==0 && strcmp(TextEntreePrenom,"")==0 && strcmp(TextEntreeDateNaissance,"")==0 && strcmp(TextEntreeGroupe,"")==0)
    {

        RemplissageListDesClasses(Emplacement);
        gtk_widget_hide(frame1);
        gtk_widget_hide(aspectframe1);
        gtk_switch_set_active(GTK_SWITCH(SwitchImage), (gboolean) FALSE);
        gtk_widget_hide(frameImage);
        ImageActive = 0;
        gtk_widget_hide(window2);
        gtk_widget_show(window1);
        Clear_Add_Student();

    }

    else
    {

        GtkWidget *pRetour;

        gchar* sUtf8 = 0;
        gchar* bUtf8 = 0;

        bUtf8 = g_locale_from_utf8("Vous avez fait des changements qui ne sont pas encore enregistrer \n Voulez-vous vraiment retourner à la page d'accueil ? ", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);


        pRetour = gtk_message_dialog_new (GTK_WINDOW(window2),
                                          GTK_DIALOG_MODAL,
                                          GTK_MESSAGE_QUESTION,
                                          GTK_BUTTONS_YES_NO,
                                          sUtf8);

        g_free(bUtf8);
        g_free(sUtf8);

        switch(gtk_dialog_run(GTK_DIALOG(pRetour)))
        {
        case GTK_RESPONSE_YES:
            gtk_widget_destroy(pRetour);
            RemplissageListDesClasses(Emplacement);
            gtk_widget_hide(frame1);
            gtk_widget_hide(aspectframe1);
            gtk_switch_set_active(GTK_SWITCH(SwitchImage), (gboolean) FALSE);
            gtk_widget_hide(frameImage);
            gtk_widget_hide(window2);
            gtk_widget_show(window1);
            Clear_Add_Student();
            break;
        case GTK_RESPONSE_NO:
            gtk_widget_destroy(pRetour);
            break;
        }


    }
}


G_MODULE_EXPORT void on_btnQuitter2_clicked(GtkButton *b)
{

    GtkWidget *pQuitter;

    pQuitter = gtk_message_dialog_new (GTK_WINDOW(window2),
                                       GTK_DIALOG_MODAL,
                                       GTK_MESSAGE_QUESTION,
                                       GTK_BUTTONS_YES_NO,
                                       "Voulez-vous vraiment\nquitter le programme?");

    switch(gtk_dialog_run(GTK_DIALOG(pQuitter)))
    {
    case GTK_RESPONSE_YES:
        gtk_main_quit();
        break;
    case GTK_RESPONSE_NO:
        gtk_widget_destroy(pQuitter);
        break;
    }


}

static void activate_SwitchImage(GObject *switcher,GParamSpec *pspec, gpointer user_data)
{

    if (gtk_switch_get_active (GTK_SWITCH (switcher)))
    {
        gtk_widget_show(frameImage);
        ImageActive = 1;
    }
    else
    {
        gtk_widget_hide(frameImage);
        ImageActive = 0;
    }

}

void Clear_Add_Student()
{

    char TextEntreeNom[MAXCHARS];
    char TextEntreePrenom[MAXCHARS];
    char TextEntreeDateNaissance[MAXCHARS];
    char TextEntreeGroupe[MAXCHARS];
    char TextEntreeNationalite[MAXCHARS];


    TextEntreeNom[0]=0;
    TextEntreePrenom[0]=0;
    TextEntreeDateNaissance[0]=0;
    TextEntreeGroupe[0]=0;
    TextEntreeNationalite[0]=0;

    gtk_entry_set_text(GTK_ENTRY(EntreeNom), (const gchar* ) TextEntreeNom);
    gtk_entry_set_text(GTK_ENTRY(EntreePrenom), (const gchar* ) TextEntreePrenom);
    gtk_entry_set_text(GTK_ENTRY(EntreeDate), (const gchar* ) TextEntreeDateNaissance);
    gtk_entry_set_text(GTK_ENTRY(EntreeGroupe), (const gchar* ) TextEntreeGroupe);
    gtk_entry_set_text(GTK_ENTRY(EntreeNationalite), (const gchar* ) TextEntreeNationalite);
    gtk_file_chooser_unselect_all(GTK_FILE_CHOOSER(Parcourir));
    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(ComboAddSexe));
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(ComboAddSexe), NULL,(const gchar*) "Homme");
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(ComboAddSexe), NULL,(const gchar*) "Femme");

    DonneesEleveToLabel();

    RemplissageListDesEleves();


}

G_MODULE_EXPORT void on_Parcourir_file_set(GtkFileChooserButton *f)
{

    char ImageEmplacementLocal[MAXCHARS];

    strcpy(ImageEmplacementLocal, gtk_file_chooser_get_filename (GTK_FILE_CHOOSER(f)));

    if (strstr(ImageEmplacementLocal,".png"))
    {
        strcpy(Extension,"png");
    }
    else if (strstr(ImageEmplacementLocal,".jpg"))
    {
        strcpy(Extension,"jpg");
    }
    else if (strstr(ImageEmplacementLocal,".jpeg"))
    {
        strcpy(Extension,"jpeg");
    }
    else if (strstr(ImageEmplacementLocal,".bmp"))
    {
        strcpy(Extension,"bmp");
    }

    strcpy(ImageEmplacement,ImageEmplacementLocal);

}


G_MODULE_EXPORT void on_btnAjouterOfficielle_clicked(GtkButton *b)
{

    char Classe[MAXCHARS], TextEntreeNom[MAXCHARS], TextEntreePrenom[MAXCHARS], TextEntreeDateNaissance[MAXCHARS], TextEntreeGroupe[MAXCHARS];
    char EleveExiste[MAXCHARS], TextEntreeNationalite[MAXCHARS];
    gchar *TextSexe = 0;

    strcpy(Classe, gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(ComboAddStudentInClass)));

    strcpy(TextEntreeNom, gtk_entry_get_text(GTK_ENTRY(EntreeNom)));

    strcpy(TextEntreePrenom, gtk_entry_get_text(GTK_ENTRY(EntreePrenom)));

    strcpy(TextEntreeDateNaissance, gtk_entry_get_text(GTK_ENTRY(EntreeDate)));

    strcpy(TextEntreeGroupe, gtk_entry_get_text(GTK_ENTRY(EntreeGroupe)));

    strcpy(TextEntreeNationalite, gtk_entry_get_text(GTK_ENTRY(EntreeNationalite)));

    TextSexe = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(ComboAddSexe));


    if(Classe == 0 || strcmp(TextEntreeNom,"") == 0 || strcmp(TextEntreePrenom,"") == 0 || strcmp(TextEntreeDateNaissance,"") == 0 || TextSexe == NULL || strcmp(TextEntreeGroupe,"") == 0 || strcmp(TextEntreeNationalite,"") == 0 ||( ImageActive == 1 && gtk_file_chooser_get_filename (GTK_FILE_CHOOSER(Parcourir)) == NULL))
    {

        if (Classe == 0)
        {
            MessageMissingInfo(0);
        }
        if (strcmp(TextEntreeNom,"") == 0)
        {
            MessageMissingInfo(1);
        }
        if (strcmp(TextEntreePrenom,"") == 0)
        {
            MessageMissingInfo(2);
        }
        if (strcmp(TextEntreeDateNaissance,"") == 0)
        {
            MessageMissingInfo(3);
        }
        if (TextSexe == NULL)
        {
            MessageMissingInfo(4);

        }
        if (strcmp(TextEntreeGroupe,"") == 0)
        {
            MessageMissingInfo(5);
        }
        if (strcmp(TextEntreeNationalite,"") == 0)
        {
            MessageMissingInfo(6);
        }
        if (ImageActive == 1)
        {
            if (gtk_file_chooser_get_filename (GTK_FILE_CHOOSER(Parcourir)) == NULL)
            {
                MessageMissingInfo(7);
            }
        }
    }
    else
    {


        strcpy(Classe, gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(ComboAddStudentInClass)));
        strcpy(TextEntreeNom, gtk_entry_get_text(GTK_ENTRY(EntreeNom)));


        for (int i = 0; Classe[i]!='\0'; i++)
        {
            if(Classe[i] == Espace)
            {
                Classe[i] = Tiret;
            }
        }

        for (int i = 0; Classe[i]!='\0'; i++)
        {

            if(Classe[i] >= 'a' && Classe[i] <= 'z')
            {

                Classe[i] = Classe[i] - 32;

            }
        }


        for (int i = 0; TextEntreeNom[i]!='\0'; i++)
        {
            if(TextEntreeNom[i] == Espace)
            {
                TextEntreeNom[i] = Tiret;
            }
        }

        for (int i = 0; TextEntreeNom[i]!='\0'; i++)
        {

            if(TextEntreeNom[i] >= 'a' && TextEntreeNom[i] <= 'z')
            {

                TextEntreeNom[i] = TextEntreeNom[i] - 32;

            }
        }

        strcpy(TextEntreePrenom, gtk_entry_get_text(GTK_ENTRY(EntreePrenom)));


        for (int i = 0; TextEntreePrenom[i]!='\0'; i++)
        {
            if(TextEntreePrenom[i] == Espace)
            {
                TextEntreePrenom[i] = Tiret;
            }
        }


        for (int i = 0; TextEntreePrenom[i]!='\0'; i++)
        {

            if(TextEntreePrenom[i] >= 'a' && TextEntreePrenom[i] <= 'z')
            {

                TextEntreePrenom[i] = TextEntreePrenom[i] - 32;

            }
        }

        strcpy(TextEntreeDateNaissance, gtk_entry_get_text(GTK_ENTRY(EntreeDate)));
        strcpy(TextEntreeGroupe, gtk_entry_get_text(GTK_ENTRY(EntreeGroupe)));

        for (int i = 0; TextEntreeGroupe[i]!='\0'; i++)
        {
            if(TextEntreeGroupe[i] == Espace)
            {
                TextEntreeGroupe[i] = Tiret;
            }
        }

        for (int i = 0; TextEntreeNationalite[i]!='\0'; i++)
        {
            if(TextEntreeNationalite[i] == Espace)
            {
                TextEntreeNationalite[i] = Tiret;
            }
        }


        TextSexe = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(ComboAddSexe));

        strcpy(EleveExiste, DossierDeTravail);
        strcat(EleveExiste, "\\");
        strcat(EleveExiste, Classe);
        strcat(EleveExiste, "\\");
        strcat(EleveExiste, TextEntreeNom);
        strcat(EleveExiste, "-");
        strcat(EleveExiste, TextEntreePrenom);
        strcat(EleveExiste, ".txt");

        if( access( EleveExiste, F_OK ) != -1 )
        {

            GtkWidget *pErreur;


            gchar* sUtf8 = 0;
            gchar* bUtf8 = 0;

            bUtf8 = g_locale_from_utf8(" Attention! une élève existe déja avec ces Données\n S'il vous plait changer Les données puis réssayer ", -1, NULL, NULL, NULL);

            sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);



            pErreur = gtk_message_dialog_new (GTK_WINDOW(window2),
                                              GTK_DIALOG_MODAL,
                                              GTK_MESSAGE_ERROR,
                                              GTK_BUTTONS_OK,
                                              sUtf8);

            gtk_dialog_run(GTK_DIALOG(pErreur));

            gtk_widget_destroy(pErreur);

            g_free(bUtf8);
            g_free(sUtf8);


        }
        else
        {

            char ImageStatus[MAXCHARS];
            int TexteCopiedSexe = 0;

            if (strcmp(TextSexe,"Homme") == 0)
            {
                TexteCopiedSexe = 0;
            }
            else if (strcmp(TextSexe,"Femme")== 0)
            {
                TexteCopiedSexe = 1;
            }

            if (ImageActive == 1)
            {
                if (gtk_file_chooser_get_filename (GTK_FILE_CHOOSER(Parcourir)) != NULL)
                {

                    char Commande[MAXCHARS];

                    strcpy(Commande, DossierDeTravail);
                    strcat(Commande, "\\");

                    strcat(Commande, Classe);
                    strcat(Commande, "\\");

                    strcat(Commande, TextEntreeNom);
                    strcat(Commande, "-");
                    strcat(Commande, TextEntreePrenom);
                    strcat(Commande, ".");
                    strcat(Commande, Extension);

                    CopyFile(ImageEmplacement,Commande,0);

                    strcpy(ImageStatus, "Oui");

                }
                else
                {

                    strcpy(ImageStatus, "Non");
                    strcpy(Extension, "Nothing");
                }
            }
            else
            {
                strcpy(ImageStatus, "Non");
                strcpy(Extension, "Nothing");
            }

            char NomEleve[MAXCHARS], PrenomEleve[MAXCHARS];

            strcpy(NomEleve, gtk_entry_get_text(GTK_ENTRY(EntreeNom)));

            strcpy(PrenomEleve, gtk_entry_get_text(GTK_ENTRY(EntreePrenom)));


            for (int i = 0; NomEleve[i]!='\0'; i++)
            {
                if(NomEleve[i] == Espace)
                {
                    NomEleve[i] = Tiret;
                }
            }

            for (int i = 0; PrenomEleve[i]!='\0'; i++)
            {
                if(PrenomEleve[i] == Espace)
                {
                    PrenomEleve[i] = Tiret;
                }
            }


            FILE* fichier = NULL;

            fichier = fopen(EleveExiste,"w");

            if (fichier != NULL)
            {

                fprintf(fichier,"ID: %d\nNom: %s\nPrenom: %s\nDate De Naissance: %s\nNationalite: %s\nSex: %d\nGroupe: %s\nImage: %s\nExtension: %s",  IDFromFile + 1, NomEleve, PrenomEleve, DateSauvegrader, TextEntreeNationalite, TexteCopiedSexe, TextEntreeGroupe, ImageStatus, Extension);

                fclose(fichier);

            }

            char AllTXT[MAXCHARS];

            strcpy(AllTXT, DossierDeTravail);
            strcat(AllTXT, "\\");
            strcat(AllTXT, Classe);
            strcat(AllTXT, "\\");
            strcat(AllTXT, "eleves.txt");

            FILE* EleveAllClasse = NULL;

            EleveAllClasse = fopen(AllTXT,"a");

            if (EleveAllClasse != NULL)
            {

                SupprimerLigneVide(NomEleve);
                SupprimerLigneVide(PrenomEleve);

                fprintf(EleveAllClasse,"%s-%s\n", NomEleve, PrenomEleve);

                fclose(EleveAllClasse);

            }

            GtkWidget *pInformation;

            gchar* sUtf8 = 0;
            gchar* bUtf8 = 0;

            bUtf8 = g_locale_from_utf8(" élève ajouté avec succès ! ", -1, NULL, NULL, NULL);

            sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);



            pInformation = gtk_message_dialog_new (GTK_WINDOW(window2),
                                                   GTK_DIALOG_MODAL,
                                                   GTK_MESSAGE_INFO,
                                                   GTK_BUTTONS_OK,
                                                   sUtf8);

            gtk_dialog_run(GTK_DIALOG(pInformation));

            gtk_widget_destroy(pInformation);

            g_free(bUtf8);
            g_free(sUtf8);

            Clear_Add_Student();

            IDFromFile += 1;

            SetIDAndPass();

        }
    }
}



void MessageMissingInfo(int type)
{
    GtkWidget *pErreur;

    gchar* sUtf8 = 0;
    gchar* bUtf8 = 0;


    if (type == 0)
    {
        bUtf8 = g_locale_from_utf8(" Veuillez choisir une Classe d'abord ", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);

    }
    if (type == 1)
    {

        bUtf8 = g_locale_from_utf8(" Entrer le Nom d'élève s'il vous plaît ", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);

    }
    if (type == 2)
    {

        bUtf8 = g_locale_from_utf8(" Entrer le Prénom d'élève s'il vous plaît ", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);

    }
    if (type == 3)
    {
        bUtf8 = g_locale_from_utf8(" Entrer la date de Naissance de l'élève s'il vous plaît ", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);

    }
    if (type == 4)
    {
        bUtf8 = g_locale_from_utf8(" Veuillez choisir le sexe d'élève s'il vous plaît ", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);
    }

    if (type == 5)
    {
        bUtf8 = g_locale_from_utf8(" Veuillez Entrer le groupe s'il vous plaît ", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);
    }
    if (type == 6)
    {
        bUtf8 = g_locale_from_utf8(" Veuillez Entrer la Nationalité d'élève s'il vous plaît ", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);
    }
    if (type == 7)
    {
        bUtf8 = g_locale_from_utf8(" Veuillez Entrer une image s'il vous plaît ", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);
    }


    pErreur = gtk_message_dialog_new (GTK_WINDOW(window2),
                                      GTK_DIALOG_MODAL,
                                      GTK_MESSAGE_ERROR,
                                      GTK_BUTTONS_OK,
                                      sUtf8);

    gtk_dialog_run(GTK_DIALOG(pErreur));

    gtk_widget_destroy(pErreur);

    g_free(bUtf8);
    g_free(sUtf8);

}


G_MODULE_EXPORT void on_EntreeDate_focus_in_event(GtkEntry *e)
{

    if(Repetition == 0)
    {

        Repetition = 1;
        GtkWidget *pInformation;

        pInformation = gtk_message_dialog_new (GTK_WINDOW(window2),
                                               GTK_DIALOG_MODAL,
                                               GTK_MESSAGE_INFO,
                                               GTK_BUTTONS_OK,
                                               " Appuyer double clique avec la souris sur la date pour confirmer votre choix ");

        gtk_dialog_run(GTK_DIALOG(pInformation));

        gtk_widget_destroy(pInformation);


    }

    gtk_widget_show(calendar1);
}

G_MODULE_EXPORT void on_calendar1_day_selected_double_click(GtkCalendar *c)
{

    char DateEntrer[MAXCHARS];

    guint year, month, day;

    gtk_calendar_get_date(GTK_CALENDAR (calendar1), &year, &month, &day);

    sprintf(DateEntrer, "%d-%d-%d", year, month+1, day);

    gtk_entry_set_text(GTK_ENTRY(EntreeDate), (const gchar* ) DateEntrer );

    strcpy(DateSauvegrader,DateEntrer);

    gtk_widget_hide(calendar1);

    Repetition = 0;

}

G_MODULE_EXPORT void on_btnSupprimer_clicked(GtkButton *b)
{

    char Message[MAXCHARS], NomEleve[MAXCHARS], PrenomEleve[MAXCHARS];

    strcpy(NomEleve, gtk_label_get_text(GTK_LABEL(lblNom)));
    strcpy(PrenomEleve, gtk_label_get_text(GTK_LABEL(lblPrenom)));

    if((strcmp(NomEleve,"label")==0) || (strcmp(PrenomEleve,"label")==0))
    {

        GtkWidget *pErreur;

        gchar* sUtf8 = 0;
        gchar* bUtf8 = 0;

        bUtf8 = g_locale_from_utf8(" Veuillez choisissais un élève d'abord ! ", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);



        pErreur = gtk_message_dialog_new (GTK_WINDOW(window1),
                                          GTK_DIALOG_MODAL,
                                          GTK_MESSAGE_ERROR,
                                          GTK_BUTTONS_OK,
                                          sUtf8);

        gtk_dialog_run(GTK_DIALOG(pErreur));

        gtk_widget_destroy(pErreur);


        g_free(bUtf8);
        g_free(sUtf8);

    }
    else
    {

        GtkWidget *pSupprimer;

        strcpy(Message, " Voulez-vous vraiment\nSupprimer '");
        strcat(Message, NomEleve);
        strcat(Message, " ");
        strcat(Message, PrenomEleve);
        strcat(Message, "' ? ");

        pSupprimer = gtk_message_dialog_new (GTK_WINDOW(window1),
                                             GTK_DIALOG_MODAL,
                                             GTK_MESSAGE_QUESTION,
                                             GTK_BUTTONS_YES_NO,
                                             (const gchar*) Message);

        switch(gtk_dialog_run(GTK_DIALOG(pSupprimer)))
        {
        case GTK_RESPONSE_YES:
            gtk_widget_destroy(pSupprimer);
            SupprimerEleveDeClasse();
            break;
        case GTK_RESPONSE_NO:
            gtk_widget_destroy(pSupprimer);
            break;
        }

    }

}

void SupprimerEleveDeClasse()
{

    char FichierTXT[MAXCHARS], FichierImage[MAXCHARS], NomEleve[MAXCHARS], PrenomEleve[MAXCHARS], Classe[MAXCHARS], EleveTXT[MAXCHARS], EleveTXTTMP[MAXCHARS];
    char NomETPrenom[MAXCHARS];

    strcpy(NomEleve, gtk_label_get_text(GTK_LABEL(lblNom)));
    strcpy(PrenomEleve, gtk_label_get_text(GTK_LABEL(lblPrenom)));
    strcpy(Classe, gtk_label_get_text(GTK_LABEL(lblClasse)));


    for (int i = 0; NomEleve[i]!='\0'; i++)
    {
        if(NomEleve[i] == Espace)
        {
            NomEleve[i] = Tiret;
        }
    }

    for (int i = 0; NomEleve[i]!='\0'; i++)
    {

        if(NomEleve[i] >= 'a' && NomEleve[i] <= 'z')
        {

            NomEleve[i] = NomEleve[i] - 32;

        }
    }

    for (int i = 0; PrenomEleve[i]!='\0'; i++)
    {
        if(PrenomEleve[i] == Espace)
        {
            PrenomEleve[i] = Tiret;
        }
    }

    for (int i = 0; Classe[i]!='\0'; i++)
    {
        if(Classe[i] == Espace)
        {
            Classe[i] = Tiret;
        }
    }

    for (int i = 0; PrenomEleve[i]!='\0'; i++)
    {

        if(PrenomEleve[i] >= 'a' && PrenomEleve[i] <= 'z')
        {

            PrenomEleve[i] = PrenomEleve[i] - 32;

        }
    }

    strcpy(FichierTXT, DossierDeTravail);
    strcat(FichierTXT, "\\");
    strcat(FichierTXT, Classe);
    strcat(FichierTXT, "\\");
    strcat(FichierTXT, NomEleve);
    strcat(FichierTXT, "-");
    strcat(FichierTXT, PrenomEleve);
    strcat(FichierTXT, ".txt");

    strcpy(FichierImage, DossierDeTravail);
    strcat(FichierImage, "\\");
    strcat(FichierImage, Classe);
    strcat(FichierImage, "\\");
    strcat(FichierImage, NomEleve);
    strcat(FichierImage, "-");
    strcat(FichierImage, PrenomEleve);
    strcat(FichierImage, ".");
    strcat(FichierImage, ElevesaAfficher.Extension);


    strcpy(EleveTXT, DossierDeTravail);
    strcat(EleveTXT, "\\");
    strcat(EleveTXT, Classe);
    strcat(EleveTXT, "\\");
    strcat(EleveTXT, "eleves.txt");

    strcpy(EleveTXTTMP, DossierDeTravail);
    strcat(EleveTXTTMP, "\\");
    strcat(EleveTXTTMP, Classe);
    strcat(EleveTXTTMP, "\\");
    strcat(EleveTXTTMP, "tmp.txt");

    strcpy(NomETPrenom, gtk_label_get_text(GTK_LABEL(lblNom)));
    strcat(NomETPrenom, "-");
    strcat(NomETPrenom, gtk_label_get_text(GTK_LABEL(lblPrenom)));


    for (int i = 0; NomETPrenom[i]!='\0'; i++)
    {
        if(NomETPrenom[i] == Espace)
        {
            NomETPrenom[i] = Tiret;
        }
    }


    SupprimerLigneVide(NomETPrenom);

    CopyFile(EleveTXT,EleveTXTTMP,0);

    char chaine[MAXCHARS];

    FILE* AllEleve = NULL;
    AllEleve = fopen(EleveTXTTMP,"r");

    FILE* fichier = NULL;
    fichier = fopen(EleveTXT,"w");

    if (fichier != NULL)
    {
        if (AllEleve != NULL)
        {

            while(fgets(chaine,1000,AllEleve) != NULL)
            {

                SupprimerLigneVide(chaine);

                if(strcmp(chaine,NomETPrenom)!=0)
                {

                    fprintf(fichier,"%s\n", chaine);

                }
                else
                {

                }
            }

            fclose(AllEleve);
        }
        fclose(fichier);

    }


    remove((const char* ) FichierTXT);
    remove((const char* ) FichierImage);
    remove((const char* ) EleveTXTTMP);


    Clear_Add_Student();

    GtkWidget *pSuccess;

    gchar* sUtf8 = 0;
    gchar* bUtf8 = 0;

    bUtf8 = g_locale_from_utf8(" élève supprimer avec succès ! ", -1, NULL, NULL, NULL);

    sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);


    pSuccess = gtk_message_dialog_new (GTK_WINDOW(window1),
                                       GTK_DIALOG_MODAL,
                                       GTK_MESSAGE_INFO,
                                       GTK_BUTTONS_OK,
                                       sUtf8);

    gtk_dialog_run(GTK_DIALOG(pSuccess));

    gtk_widget_destroy(pSuccess);

    g_free(bUtf8);
    g_free(sUtf8);

}
void DonneesEleveToLabel()
{

    gtk_label_set_text(GTK_LABEL(lblID), "label");
    gtk_label_set_text(GTK_LABEL(lblNom), "label");
    gtk_label_set_text(GTK_LABEL(lblPrenom), "label");
    gtk_label_set_text(GTK_LABEL(lblDateNaissance), "label");
    gtk_label_set_text(GTK_LABEL(lblNationalite), "label");
    gtk_label_set_text(GTK_LABEL(lblSexe), "label");
    gtk_label_set_text(GTK_LABEL(lblClasse), "label");
    gtk_label_set_text(GTK_LABEL(lblGroupe),  "label");

}

G_MODULE_EXPORT void on_btnModifier_clicked(GtkButton *b)
{

    char Message[MAXCHARS], NomEleve[MAXCHARS], PrenomEleve[MAXCHARS];

    strcpy(NomEleve, gtk_label_get_text(GTK_LABEL(lblNom)));
    strcpy(PrenomEleve, gtk_label_get_text(GTK_LABEL(lblPrenom)));
    strcpy(ClasseOriginale, gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(ComboClasses)));

    strcpy(NomOriginale, NomEleve);
    strcpy(PrenomOriginale, PrenomEleve);

    if((strcmp(NomEleve,"label")==0) || (strcmp(PrenomEleve,"label")==0))
    {

        gchar* sUtf8 = 0;
        gchar* bUtf8 = 0;

        bUtf8 = g_locale_from_utf8("Veuillez choisissais un élève d'abord ! ", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);

        GtkWidget *pErreur;

        pErreur = gtk_message_dialog_new (GTK_WINDOW(window1),
                                          GTK_DIALOG_MODAL,
                                          GTK_MESSAGE_ERROR,
                                          GTK_BUTTONS_OK,
                                          sUtf8);

        gtk_dialog_run(GTK_DIALOG(pErreur));

        gtk_widget_destroy(pErreur);

        g_free(bUtf8);
        g_free(sUtf8);



    }
    else
    {

        GtkWidget *pModifier;

        strcpy(Message, " Voulez-vous vraiment\nModifier '");
        strcat(Message, NomEleve);
        strcat(Message, " ");
        strcat(Message, PrenomEleve);
        strcat(Message, "' ? ");

        pModifier = gtk_message_dialog_new (GTK_WINDOW(window1),
                                            GTK_DIALOG_MODAL,
                                            GTK_MESSAGE_QUESTION,
                                            GTK_BUTTONS_YES_NO,
                                            (const gchar*) Message);

        switch(gtk_dialog_run(GTK_DIALOG(pModifier)))
        {
        case GTK_RESPONSE_YES:
            ModifierEleve();
            gtk_widget_destroy(pModifier);
            break;
        case GTK_RESPONSE_NO:
            gtk_widget_destroy(pModifier);
            break;
        }
    }
}

void ModifierEleve()
{

    char Emplacement[]= {"Modifier"};

    strcpy(UnchagedClasse,(gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(ComboClasses))));

    Clear_Modifier_Student();

    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(ComboModifierClasse));

    RemplissageDonneesEleves(Emplacement);

    RemplissageListDesClasses(Emplacement);

    if (strcmp(ElevesaAfficher.Image,"Oui")==0)
    {
        SavedStatus1 = 1;
        SavedStatus2 = 0;
    }
    else
    {
        SavedStatus1 = 0;
        SavedStatus2 = 0;
    }

    gtk_widget_hide(frame1);
    gtk_widget_hide(aspectframe1);
    gtk_widget_hide(window1);
    gtk_widget_show(window3);

}


void Clear_Modifier_Student()
{

    char TextEntreeModifierNom[MAXCHARS];
    char TextEntreeModifierPrenom[MAXCHARS];
    char TextEntreeModifierDateNaissance[MAXCHARS];
    char TextEntreeModifierGroupe[MAXCHARS];
    char TextEntreeModifierNationalite[MAXCHARS];


    gtk_switch_set_active(GTK_SWITCH (SwitchModifierImage), FALSE);
    gtk_widget_hide(FrameModifierImage);
    ModifierImageActive = 0;

    TextEntreeModifierNom[0]=0;
    TextEntreeModifierPrenom[0]=0;
    TextEntreeModifierDateNaissance[0]=0;
    TextEntreeModifierGroupe[0]=0;
    TextEntreeModifierNationalite[0]=0;

    gtk_entry_set_text(GTK_ENTRY(EntreeModifierNom), (const gchar* ) TextEntreeModifierNom);
    gtk_entry_set_text(GTK_ENTRY(EntreeModifierPrenom), (const gchar* ) TextEntreeModifierPrenom);
    gtk_entry_set_text(GTK_ENTRY(EntreeModifierDate), (const gchar* ) TextEntreeModifierDateNaissance);
    gtk_entry_set_text(GTK_ENTRY(EntreeModifierGroupe), (const gchar* ) TextEntreeModifierGroupe);
    gtk_entry_set_text(GTK_ENTRY(EntreeModifierNationalite), (const gchar* ) TextEntreeModifierNationalite);


    gtk_file_chooser_unselect_all(GTK_FILE_CHOOSER(ParcourirNouvelleImage));
    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(ComboModifierSex));

    gtk_switch_set_active(GTK_SWITCH (SwitchModifierImage), FALSE);
    gtk_switch_set_active(GTK_SWITCH (switchImageExiste), FALSE);
    gtk_widget_hide(FrameModifierImage);
    ModifierImageActive = 0;
    StatusImage = 0;

}

static void activate_SwitchModifierImage(GObject *switcher,GParamSpec *pspec, gpointer user_data)
{

    if (gtk_switch_get_active (GTK_SWITCH (switcher)))
    {
        gtk_widget_show(FrameModifierImage);
        ModifierImageActive = 1;
    }
    else
    {
        gtk_widget_hide(FrameModifierImage);
        ModifierImageActive = 0;
    }

}





static void activate_switchImageExiste(GObject *switcher,GParamSpec *pspec, gpointer user_data)
{

    if (gtk_switch_get_active (GTK_SWITCH (switcher)))
    {
        StatusImage = 1;
        gtk_widget_show(label35);
        gtk_widget_show(SwitchModifierImage);
    }
    else
    {
        StatusImage = 0;
        gtk_switch_set_active(GTK_SWITCH (SwitchModifierImage), FALSE);
        gtk_widget_hide(label35);
        gtk_widget_hide(SwitchModifierImage);
    }

}


G_MODULE_EXPORT void on_BtnQuitter3_clicked(GtkButton *b)
{

    GtkWidget *pQuitter;

    pQuitter = gtk_message_dialog_new (GTK_WINDOW(window3),
                                       GTK_DIALOG_MODAL,
                                       GTK_MESSAGE_QUESTION,
                                       GTK_BUTTONS_YES_NO,
                                       "Voulez-vous vraiment\nquitter le programme?");

    switch(gtk_dialog_run(GTK_DIALOG(pQuitter)))
    {
    case GTK_RESPONSE_YES:
        gtk_main_quit();
        break;
    case GTK_RESPONSE_NO:
        gtk_widget_destroy(pQuitter);
        break;
    }

}


G_MODULE_EXPORT void on_BtnRetour3_clicked(GtkButton *b)
{

    char Emplacement [] = {"Accueil"};
    const gchar *TextEntreeNom;
    const gchar *TextEntreePrenom;
    const gchar *TextEntreeDateNaissance;
    const gchar *TextEntreeGroupe;

    TextEntreeNom = gtk_entry_get_text(GTK_ENTRY(EntreeModifierNom));
    TextEntreePrenom = gtk_entry_get_text(GTK_ENTRY(EntreeModifierPrenom));
    TextEntreeDateNaissance = gtk_entry_get_text(GTK_ENTRY(EntreeModifierDate));
    TextEntreeGroupe = gtk_entry_get_text(GTK_ENTRY(EntreeModifierGroupe));


    if ((strcmp(TextEntreeNom,ElevesaAfficher.Nom)==0) && (strcmp(TextEntreePrenom,ElevesaAfficher.Prenom)==0) && (strcmp(TextEntreeDateNaissance,DateSauvegrader2)==0) && (strcmp(TextEntreeGroupe,ElevesaAfficher.Groupe)==0) && ((SavedStatus1 - StatusImage) == 0) && ((ModifierImageActive == 0)))
    {

        RemplissageListDesClasses(Emplacement);
        RemplissageListDesEleves();
        gtk_widget_hide(frame1);
        DonneesEleveToLabel();
        gtk_widget_hide(aspectframe1);
        gtk_widget_hide(frameImage);
        gtk_widget_hide(window3);
        gtk_widget_show(window1);
        Clear_Modifier_Student();

    }

    else
    {

        GtkWidget *pRetour;

        gchar* sUtf8 = 0;
        gchar* bUtf8 = 0;

        bUtf8 = g_locale_from_utf8("Vous avez fait des changements qui ne sont pas encore enregistrer \nVoulez-vous vraiment retourner à la page d'accueil ?", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);



        pRetour = gtk_message_dialog_new (GTK_WINDOW(window3),
                                          GTK_DIALOG_MODAL,
                                          GTK_MESSAGE_QUESTION,
                                          GTK_BUTTONS_YES_NO,
                                          sUtf8);

        switch(gtk_dialog_run(GTK_DIALOG(pRetour)))
        {
        case GTK_RESPONSE_YES:
            gtk_widget_destroy(pRetour);
            RemplissageListDesClasses(Emplacement);
            RemplissageListDesEleves();
            gtk_widget_hide(frame1);
            DonneesEleveToLabel();
            gtk_widget_hide(aspectframe1);
            gtk_widget_hide(frameImage);
            gtk_widget_hide(window3);
            gtk_widget_show(window1);
            Clear_Modifier_Student();
            break;
        case GTK_RESPONSE_NO:
            gtk_widget_destroy(pRetour);
            break;
        }

        g_free(bUtf8);
        g_free(sUtf8);

    }
}

G_MODULE_EXPORT void on_EntreeModifierDate_focus_in_event(GtkEntry *e)
{

    if(Repetition2 == 0)
    {
        Repetition2 = 1;
        GtkWidget *pInformation;

        pInformation = gtk_message_dialog_new (GTK_WINDOW(window3),
                                               GTK_DIALOG_MODAL,
                                               GTK_MESSAGE_INFO,
                                               GTK_BUTTONS_OK,
                                               " Appuyer double clique avec la souris sur la date pour confirmer votre choix ");

        gtk_dialog_run(GTK_DIALOG(pInformation));

        gtk_widget_destroy(pInformation);


    }

    gtk_widget_show(calendar2);


}


G_MODULE_EXPORT void on_calendar2_day_selected_double_click(GtkCalendar *c)
{

    char DateEditerEntrer[MAXCHARS];

    guint year, month, day;

    gtk_calendar_get_date(GTK_CALENDAR (calendar2), &year, &month, &day);

    sprintf(DateEditerEntrer, "%d-%d-%d", year, month+1, day);

    gtk_entry_set_text(GTK_ENTRY(EntreeModifierDate), (const gchar* ) DateEditerEntrer);

    strcpy(DateModifierSauvegrader,DateEditerEntrer);

    gtk_widget_hide(calendar2);

    Repetition2 = 0;

}


G_MODULE_EXPORT void on_BtnSaveChanges_clicked(GtkButton *b)
{
    char Classe[MAXCHARS], TextEntreeNom[MAXCHARS], TextEntreePrenom[MAXCHARS], TextEntreeDateNaissance[MAXCHARS], TextEntreeGroupe[MAXCHARS];
    char EleveExiste[MAXCHARS], TextEntreeNationalite[MAXCHARS], DoubleNom[MAXCHARS], DoublePrenom[MAXCHARS], ClasseOriginaleTiret[MAXCHARS];
    gchar *TextSexe = 0;
    int NEXISTEPAS = 0;

    strcpy(Classe, gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(ComboModifierClasse)));

    strcpy(TextEntreeNom, gtk_entry_get_text(GTK_ENTRY(EntreeModifierNom)));

    strcpy(DoubleNom, TextEntreeNom);

    strcpy(TextEntreePrenom, gtk_entry_get_text(GTK_ENTRY(EntreeModifierPrenom)));

    strcpy(DoublePrenom, TextEntreePrenom);
    strcpy(ClasseOriginaleTiret, ClasseOriginale);

    strcpy(TextEntreeDateNaissance, gtk_entry_get_text(GTK_ENTRY(EntreeModifierDate)));

    strcpy(TextEntreeGroupe, gtk_entry_get_text(GTK_ENTRY(EntreeModifierGroupe)));

    strcpy(TextEntreeNationalite, gtk_entry_get_text(GTK_ENTRY(EntreeModifierNationalite)));

    TextSexe = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(ComboModifierSex));

    if (((strcmp(ElevesaAfficher.Image, "Non") == 0) && (StatusImage == 1) && (ModifierImageActive == 1) && (gtk_file_chooser_get_filename (GTK_FILE_CHOOSER(ParcourirNouvelleImage)) == NULL)) || ((strcmp(ElevesaAfficher.Image, "Non") == 0) && (StatusImage == 1) && (ModifierImageActive == 0)) || Classe == 0 || strcmp(TextEntreeNom,"") == 0 || strcmp(TextEntreePrenom,"") == 0 || strcmp(TextEntreeDateNaissance,"") == 0 || TextSexe == NULL || strcmp(TextEntreeGroupe,"") == 0 || strcmp(TextEntreeNationalite,"") == 0 ||( StatusImage == 1 && ModifierImageActive == 1 && gtk_file_chooser_get_filename (GTK_FILE_CHOOSER(Parcourir)) == NULL))
    {

        if (Classe == 0)
        {
            MessageMissingInfoEdit(0);
        }
        if (strcmp(TextEntreeNom,"") == 0)
        {
            MessageMissingInfoEdit(1);
        }
        if (strcmp(TextEntreePrenom,"") == 0)
        {
            MessageMissingInfoEdit(2);
        }
        if (strcmp(TextEntreeDateNaissance,"") == 0)
        {
            MessageMissingInfoEdit(3);
        }
        if (TextSexe == NULL)
        {
            MessageMissingInfoEdit(4);

        }
        if (strcmp(TextEntreeGroupe,"") == 0)
        {
            MessageMissingInfoEdit(5);
        }
        if (strcmp(TextEntreeNationalite,"") == 0)
        {
            MessageMissingInfoEdit(6);
        }

        if (((strcmp(ElevesaAfficher.Image, "Non") == 0) && (StatusImage == 1) && (ModifierImageActive == 1) && (gtk_file_chooser_get_filename (GTK_FILE_CHOOSER(ParcourirNouvelleImage)) == NULL)) || ((strcmp(ElevesaAfficher.Image, "Non") == 0) && (StatusImage == 1) && (ModifierImageActive == 0)))
        {
            MessageMissingInfoEdit(7);
        }
        else if ((StatusImage == 1) && (ModifierImageActive == 1) && (gtk_file_chooser_get_filename (GTK_FILE_CHOOSER(ParcourirNouvelleImage)) == NULL))
        {
            MessageMissingInfoEdit(7);
        }
        else if ((StatusImage == 1) && (ModifierImageActive == 1) && (gtk_file_chooser_get_filename (GTK_FILE_CHOOSER(ParcourirNouvelleImage)) != NULL))
        {
            goto LASTRESORT;
        }
    }
    else
    {

LASTRESORT:

        strcpy(Classe, gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(ComboModifierClasse)));
        strcpy(TextEntreeNom, gtk_entry_get_text(GTK_ENTRY(EntreeModifierNom)));


        for (int i = 0; Classe[i]!='\0'; i++)
        {
            if(Classe[i] == Espace)
            {
                Classe[i] = Tiret;
            }
        }

        for (int i = 0; Classe[i]!='\0'; i++)
        {

            if(Classe[i] >= 'a' && Classe[i] <= 'z')
            {

                Classe[i] = Classe[i] - 32;

            }
        }

        for (int i = 0; ClasseOriginaleTiret[i]!='\0'; i++)
        {
            if(ClasseOriginaleTiret[i] == Espace)
            {
                ClasseOriginaleTiret[i] = Tiret;
            }
        }

        for (int i = 0; ClasseOriginaleTiret[i]!='\0'; i++)
        {

            if(ClasseOriginaleTiret[i] >= 'a' && ClasseOriginaleTiret[i] <= 'z')
            {

                ClasseOriginaleTiret[i] = ClasseOriginaleTiret[i] - 32;

            }
        }


        for (int i = 0; TextEntreeNom[i]!='\0'; i++)
        {
            if(TextEntreeNom[i] == Espace)
            {
                TextEntreeNom[i] = Tiret;
            }
        }

        for (int i = 0; TextEntreeNom[i]!='\0'; i++)
        {

            if(TextEntreeNom[i] >= 'a' && TextEntreeNom[i] <= 'z')
            {

                TextEntreeNom[i] = TextEntreeNom[i] - 32;

            }
        }


        strcpy(TextEntreePrenom, gtk_entry_get_text(GTK_ENTRY(EntreeModifierPrenom)));


        for (int i = 0; TextEntreePrenom[i]!='\0'; i++)
        {
            if(TextEntreePrenom[i] == Espace)
            {
                TextEntreePrenom[i] = Tiret;
            }
        }


        for (int i = 0; TextEntreePrenom[i]!='\0'; i++)
        {

            if(TextEntreePrenom[i] >= 'a' && TextEntreePrenom[i] <= 'z')
            {

                TextEntreePrenom[i] = TextEntreePrenom[i] - 32;

            }
        }

        strcpy(TextEntreeDateNaissance, gtk_entry_get_text(GTK_ENTRY(EntreeModifierDate)));
        strcpy(TextEntreeGroupe, gtk_entry_get_text(GTK_ENTRY(EntreeModifierGroupe)));

        for (int i = 0; TextEntreeGroupe[i]!='\0'; i++)
        {
            if(TextEntreeGroupe[i] == Espace)
            {
                TextEntreeGroupe[i] = Tiret;
            }
        }

        for (int i = 0; TextEntreeNationalite[i]!='\0'; i++)
        {
            if(TextEntreeNationalite[i] == Espace)
            {
                TextEntreeNationalite[i] = Tiret;
            }
        }


        TextSexe = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(ComboModifierSex));


        int Resultat = 0;

        char ImageLocation[MAXCHARS];

        strcpy(EleveExiste, DossierDeTravail);
        strcat(EleveExiste, "\\");
        strcat(EleveExiste, Classe);
        strcat(EleveExiste, "\\");
        strcat(EleveExiste, TextEntreeNom);
        strcat(EleveExiste, "-");
        strcat(EleveExiste, TextEntreePrenom);
        strcat(EleveExiste, ".txt");


        strcpy(ImageLocation, DossierDeTravail);
        strcat(ImageLocation, "\\");
        strcat(ImageLocation, Classe);
        strcat(ImageLocation, "\\");
        strcat(ImageLocation, TextEntreeNom);
        strcat(ImageLocation, "-");
        strcat(ImageLocation, TextEntreePrenom);
        strcat(ImageLocation, ".");
        strcat(ImageLocation, ElevesaAfficher.Extension);


        if( access( EleveExiste, F_OK ) != -1 )
        {

            GtkWidget *pAttention;
            char Message[MAXCHARS];


            gchar* sUtf8 = 0;
            gchar* bUtf8 = 0;



            strcpy(Message," Vous êtes sur le point d'écraser Les Données de '");

            strcat(Message,DoubleNom);
            strcat(Message," ");
            strcat(Message,DoublePrenom);

            strcat(Message,"' \n êtes-vous sur de continuer ? ");

            bUtf8 = g_locale_from_utf8(Message, -1, NULL, NULL, NULL);

            sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);

            pAttention = gtk_message_dialog_new (GTK_WINDOW(window3),
                                                 GTK_DIALOG_MODAL,
                                                 GTK_MESSAGE_QUESTION,
                                                 GTK_BUTTONS_YES_NO,
                                                 sUtf8);

            switch(gtk_dialog_run(GTK_DIALOG(pAttention)))
            {
            case GTK_RESPONSE_YES:
                Resultat = 0;
                NEXISTEPAS = 0;
                gtk_widget_destroy(pAttention);
                break;
            case GTK_RESPONSE_NO:
                Resultat = 1;
                NEXISTEPAS = 1;
                gtk_widget_destroy(pAttention);
                break;
            }
            g_free(bUtf8);
            g_free(sUtf8);
        }
        else
        {
            NEXISTEPAS = 1;
            Resultat = 0;
        }

        if (Resultat == 1)
        {

            GtkWidget *pInfo;


            gchar* sUtf8 = 0;
            gchar* bUtf8 = 0;

            bUtf8 = g_locale_from_utf8(" Rien N'as étè changé ! ", -1, NULL, NULL, NULL);

            sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);


            pInfo = gtk_message_dialog_new (GTK_WINDOW(window3),
                                            GTK_DIALOG_MODAL,
                                            GTK_MESSAGE_INFO,
                                            GTK_BUTTONS_OK,
                                            sUtf8);

            gtk_dialog_run(GTK_DIALOG(pInfo));

            gtk_widget_destroy(pInfo);

            g_free(bUtf8);
            g_free(sUtf8);
        }
        else
        {
            char NomOriginaleTiret[MAXCHARS], PrenomOriginaleTiret[MAXCHARS], ImageOriginleDir[MAXCHARS], FichierTXTOriginale[MAXCHARS], NomETPrenom[MAXCHARS];

            strcpy(NomOriginaleTiret,NomOriginale);
            strcpy(PrenomOriginaleTiret,PrenomOriginale);


            for (int i = 0; NomOriginaleTiret[i]!='\0'; i++)
            {
                if(NomOriginaleTiret[i] == Espace)
                {
                    NomOriginaleTiret[i] = Tiret;
                }
            }


            for (int i = 0; NomOriginaleTiret[i]!='\0'; i++)
            {

                if(NomOriginaleTiret[i] >= 'a' && NomOriginaleTiret[i] <= 'z')
                {

                    NomOriginaleTiret[i] = NomOriginaleTiret[i] - 32;

                }
            }


            for (int i = 0; PrenomOriginaleTiret[i]!='\0'; i++)
            {
                if(PrenomOriginaleTiret[i] == Espace)
                {
                    PrenomOriginaleTiret[i] = Tiret;
                }
            }


            for (int i = 0; PrenomOriginaleTiret[i]!='\0'; i++)
            {

                if(PrenomOriginaleTiret[i] >= 'a' && PrenomOriginaleTiret[i] <= 'z')
                {

                    PrenomOriginaleTiret[i] = PrenomOriginaleTiret[i] - 32;

                }
            }

            char NomCmp[MAXCHARS];

            strcpy(NomETPrenom,NomOriginale);
            strcat(NomETPrenom,"-");
            strcat(NomETPrenom,PrenomOriginale);

            strcpy(NomCmp,NomOriginale);
            strcat(NomCmp,"-");
            strcat(NomCmp,PrenomOriginale);

            for (int i = 0; NomCmp[i]!='\0'; i++)
            {
                if(NomCmp[i] == Espace)
                {
                    NomCmp[i] = Tiret;
                }
            }

            for (int i = 0; NomETPrenom[i]!='\0'; i++)
            {
                if(NomETPrenom[i] == Espace)
                {
                    NomETPrenom[i] = Tiret;
                }
            }

            for (int i = 0; NomETPrenom[i]!='\0'; i++)
            {

                if(NomETPrenom[i] >= 'a' && NomETPrenom[i] <= 'z')
                {

                    NomETPrenom[i] = NomETPrenom[i] - 32;

                }
            }

            strcpy(EleveExiste, DossierDeTravail);
            strcat(EleveExiste, "\\");
            strcat(EleveExiste, Classe);
            strcat(EleveExiste, "\\");
            strcat(EleveExiste, TextEntreeNom);
            strcat(EleveExiste, "-");
            strcat(EleveExiste, TextEntreePrenom);
            strcat(EleveExiste, ".txt");


            strcpy(ImageOriginleDir, DossierDeTravail);
            strcat(ImageOriginleDir, "\\");
            strcat(ImageOriginleDir, ClasseOriginaleTiret);
            strcat(ImageOriginleDir, "\\");
            strcat(ImageOriginleDir, NomOriginaleTiret);
            strcat(ImageOriginleDir, "-");
            strcat(ImageOriginleDir, PrenomOriginaleTiret);
            strcpy(FichierTXTOriginale, ImageOriginleDir);
            strcat(FichierTXTOriginale, ".txt");
            strcat(ImageOriginleDir, ".");
            strcat(ImageOriginleDir, ElevesaAfficher.Extension);



            char ImageStatus[MAXCHARS];
            int TexteCopiedSexe = 0;

            if (strcmp(TextSexe,"Homme") == 0)
            {
                TexteCopiedSexe = 0;
            }
            else if (strcmp(TextSexe,"Femme")== 0)
            {
                TexteCopiedSexe = 1;
            }

            if (StatusImage == 1)
            {

                if(ModifierImageActive == 0)
                {

                    CopyFile(ImageOriginleDir,ImageLocation,0);

                    if (NEXISTEPAS == 1)
                    {
                        remove((const char* ) ImageOriginleDir);
                    }


                    strcpy(ImageStatus, "Oui");
                    strcpy(Extension, ElevesaAfficher.Extension);

                }
                else if (ModifierImageActive == 1)
                {
                    if (gtk_file_chooser_get_filename (GTK_FILE_CHOOSER(ParcourirNouvelleImage)) != NULL)
                    {
                        char Commande[MAXCHARS];

                        strcpy(Commande, DossierDeTravail);
                        strcat(Commande, "\\");

                        strcat(Commande, Classe);
                        strcat(Commande, "\\");

                        strcat(Commande, TextEntreeNom);

                        strcat(Commande, "-");
                        strcat(Commande, TextEntreePrenom);

                        strcat(Commande, ".");
                        strcat(Commande, Extension);

                        CopyFile(ImageEmplacement,Commande,0);

                        strcpy(ImageStatus, "Oui");

                        if (NEXISTEPAS == 1)
                        {
                            remove((const char* ) ImageOriginleDir);
                        }
                    }
                    else
                    {
                        strcpy(ImageStatus, "Non");
                        strcpy(Extension, "Nothing");

                    }
                }
                else
                {
                    strcpy(ImageStatus, "Non");
                    strcpy(Extension, "Nothing");

                }
            }
            else
            {

                remove((const char* ) ImageOriginleDir);
                strcpy(ImageStatus, "Non");
                strcpy(Extension, "Nothing");
            }


            char NomEleve[MAXCHARS], PrenomEleve[MAXCHARS];

            strcpy(NomEleve, gtk_entry_get_text(GTK_ENTRY(EntreeModifierNom)));

            strcpy(PrenomEleve, gtk_entry_get_text(GTK_ENTRY(EntreeModifierPrenom)));

            for (int i = 0; NomEleve[i]!='\0'; i++)
            {
                if(NomEleve[i] == Espace)
                {
                    NomEleve[i] = Tiret;
                }
            }

            for (int i = 0; PrenomEleve[i]!='\0'; i++)
            {
                if(PrenomEleve[i] == Espace)
                {
                    PrenomEleve[i] = Tiret;
                }
            }

            char Toprint[MAXCHARS], MinToprint[MAXCHARS];

            strcpy(Toprint,TextEntreeNom);
            strcat(Toprint,"-");
            strcat(Toprint,TextEntreePrenom);

            strcpy(MinToprint,NomEleve);
            strcat(MinToprint,"-");
            strcat(MinToprint,PrenomEleve);

            FILE* fichier = NULL;

            fichier = fopen(EleveExiste,"w");


            if (fichier != NULL)
            {
                fprintf(fichier,"ID: %d\nNom: %s\nPrenom: %s\nDate De Naissance: %s\nNationalite: %s\nSex: %d\nGroupe: %s\nImage: %s\nExtension: %s",  IDnonUpdated, NomEleve, PrenomEleve, TextEntreeDateNaissance, TextEntreeNationalite, TexteCopiedSexe, TextEntreeGroupe, ImageStatus, Extension);

                fclose(fichier);

            }


            if(NEXISTEPAS == 1)
            {
                remove((const char* ) FichierTXTOriginale);
            }

            char AllTXT[MAXCHARS], TMPALLTXT[MAXCHARS], OrigTXT[MAXCHARS], OrigTXTTMP[MAXCHARS];
            int Compteur = 0;


            strcpy(AllTXT, DossierDeTravail);
            strcat(AllTXT, "\\");
            strcat(AllTXT, Classe);
            strcat(AllTXT, "\\");

            strcpy(TMPALLTXT, AllTXT);
            strcat(AllTXT, "eleves.txt");
            strcat(TMPALLTXT, "tmp.txt");

            strcpy(OrigTXT, DossierDeTravail);
            strcat(OrigTXT, "\\");
            strcat(OrigTXT, ClasseOriginaleTiret);
            strcat(OrigTXT, "\\");
            strcat(OrigTXT, "eleves.txt");

            strcpy(OrigTXTTMP, DossierDeTravail);
            strcat(OrigTXTTMP, "\\");
            strcat(OrigTXTTMP, ClasseOriginaleTiret);
            strcat(OrigTXTTMP, "\\");
            strcat(OrigTXTTMP, "tmp.txt");


            SupprimerLigneVide(NomETPrenom);
            SupprimerLigneVide(Toprint);
            SupprimerLigneVide(MinToprint);

            CopyFile(AllTXT,TMPALLTXT,0);

            CopyFile(OrigTXT,OrigTXTTMP,0);

            char chaine[MAXCHARS];


            FILE* AllEleve = NULL;
            AllEleve = fopen(TMPALLTXT,"r");

            FILE* fichiertmp = NULL;
            fichiertmp = fopen(AllTXT,"w");

            FILE* fichierOriginale = NULL;
            fichierOriginale = fopen(OrigTXT,"w");

            FILE* fichierOriginaleTmp = NULL;
            fichierOriginaleTmp = fopen(OrigTXTTMP,"r");

            if (strcmp(ClasseOriginale,Classe)==0)
            {

                if (fichiertmp != NULL)
                {

                    if (AllEleve != NULL)
                    {

                        while(fgets(chaine,1000,AllEleve) != NULL)
                        {

                            SupprimerLigneVide(chaine);

                            if (NEXISTEPAS == 0)
                            {
                                if(strcmp(chaine,NomCmp)!=0)
                                {

                                    fprintf(fichiertmp,"%s\n", chaine);

                                }
                                else
                                {

                                    fprintf(fichiertmp,"%s\n", MinToprint);

                                }
                            }
                            else if (NEXISTEPAS == 1)
                            {

                                if(Compteur == 0)
                                {
                                    fprintf(fichiertmp,"%s\n", MinToprint);
                                    Compteur++;
                                }

                                if(strcmp(chaine,NomCmp) != 0)
                                {
                                    fprintf(fichiertmp,"%s\n", chaine);

                                }
                            }
                        }

                        fclose(AllEleve);
                    }
                    fclose(fichiertmp);

                }
            }
            else
            {

                char TmpChaine[MAXCHARS];

                if (fichierOriginale != NULL)
                {

                    if (fichierOriginaleTmp != NULL)
                    {
                        while(fgets(TmpChaine,1000,fichierOriginaleTmp) != NULL)
                        {
                            SupprimerLigneVide(TmpChaine);
                            SupprimerLigneVide(Toprint);
                            SupprimerLigneVide(NomCmp);

                            if(strcmp(TmpChaine,NomCmp)!=0)
                            {
                                fprintf(fichierOriginale,"%s\n", TmpChaine);

                            }

                        }

                    }

                    fclose(fichierOriginaleTmp);
                }

                fclose(fichierOriginale);

                if (fichiertmp != NULL)
                {
                    if (AllEleve != NULL)
                    {

                    if (NEXISTEPAS == 1)
                    {

                        fprintf(fichiertmp,"%s\n", MinToprint);

                    }


                        while(fgets(chaine,1000,AllEleve) != NULL)
                        {

                            SupprimerLigneVide(chaine);

                            if (NEXISTEPAS == 0)
                            {

                                if(strcmp(chaine,NomCmp)!=0)
                                {

                                    fprintf(fichiertmp,"%s\n", chaine);

                                }
                                else
                                {

                                    fprintf(fichiertmp,"%s\n", MinToprint);

                                }
                            }
                            else if (NEXISTEPAS == 1)
                            {


                                if(strcmp(chaine,NomCmp) != 0)
                                {

                                    fprintf(fichiertmp,"%s\n", chaine);

                                }

                            }
                        }

                        fclose(AllEleve);
                    }
                    fclose(fichiertmp);

                }

                fclose(fichiertmp);

            }


        GtkWidget *pInformation;

        gchar* sUtf8 = 0;
        gchar* bUtf8 = 0;

        bUtf8 = g_locale_from_utf8(" élève Modifier avec succès ! ", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);


        pInformation = gtk_message_dialog_new (GTK_WINDOW(window3),
                                               GTK_DIALOG_MODAL,
                                               GTK_MESSAGE_INFO,
                                               GTK_BUTTONS_OK,
                                               sUtf8);

        gtk_dialog_run(GTK_DIALOG(pInformation));

        gtk_widget_destroy(pInformation);


        remove(TMPALLTXT);

        remove(OrigTXTTMP);

        g_free(bUtf8);
        g_free(sUtf8);

        Clear_Add_Student();

        Clear_Modifier_Student();

        gtk_widget_hide(window3);

        gtk_widget_show(window1);

        SetIDAndPass();

        RemplissageListDesEleves();

    }

}



}



void MessageMissingInfoEdit(int type)
{

    GtkWidget *pErreur;

    gchar* sUtf8 = 0;
    gchar* bUtf8 = 0;

    if (type == 0)
    {
        bUtf8 = g_locale_from_utf8("Veuillez choisir une Classe d'abord ", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);
    }
    if (type == 1)
    {
        bUtf8 = g_locale_from_utf8("Entrer le Nom d'élève s'il vous plaît ", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);
    }
    if (type == 2)
    {
        bUtf8 = g_locale_from_utf8("Entrer le Prénom d'élève s'il vous plaît ", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);

    }
    if (type == 3)
    {
        bUtf8 = g_locale_from_utf8("Entrer la date de Naissance de l'élève s'il vous plaît ", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);
    }
    if (type == 4)
    {
        bUtf8 = g_locale_from_utf8("Veuillez choisir le sexe d'élève s'il vous plaît ", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);

    }

    if (type == 5)
    {
        bUtf8 = g_locale_from_utf8("Veuillez Entrer le groupe s'il vous plaît ", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);
    }
    if (type == 6)
    {
        bUtf8 = g_locale_from_utf8("Veuillez Entrer la Nationalité d'élève s'il vous plaît ", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);
    }
    if (type == 7)
    {
        bUtf8 = g_locale_from_utf8("Veuillez Entrer une image s'il vous plaît ", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);
    }


    pErreur = gtk_message_dialog_new (GTK_WINDOW(window3),
                                      GTK_DIALOG_MODAL,
                                      GTK_MESSAGE_ERROR,
                                      GTK_BUTTONS_OK,
                                      sUtf8);

    gtk_dialog_run(GTK_DIALOG(pErreur));

    gtk_widget_destroy(pErreur);

    g_free(bUtf8);
    g_free(sUtf8);

}

G_MODULE_EXPORT void on_ParcourirNouvelleImage_file_set(GtkFileChooserButton *f)
{

    char ImageEmplacementLocal[MAXCHARS];

    strcpy(ImageEmplacementLocal, gtk_file_chooser_get_filename (GTK_FILE_CHOOSER(f)));

    if (strstr(ImageEmplacementLocal,".png"))
    {
        strcpy(Extension,"png");
    }
    else if (strstr(ImageEmplacementLocal,".jpg"))
    {
        strcpy(Extension,"jpg");
    }
    else if (strstr(ImageEmplacementLocal,".jpeg"))
    {
        strcpy(Extension,"jpeg");
    }
    else if (strstr(ImageEmplacementLocal,".bmp"))
    {
        strcpy(Extension,"bmp");
    }

    strcpy(ImageEmplacement,ImageEmplacementLocal);

}


G_MODULE_EXPORT void on_buttonRetour4_clicked(GtkButton *b)
{

    char Emplacement [] = {"Accueil"};
    const gchar *TextAjouter;
    const gchar *TextModifier;
    int Resultat = 0;

    TextAjouter = gtk_entry_get_text(GTK_ENTRY(entryAjouterClasse));
    TextModifier = gtk_entry_get_text(GTK_ENTRY(entryModifierClasse));


    if ((gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(RadioAjouter))) && (strcmp(TextAjouter,"")==0))
    {

        Resultat = 0;
    }
    else if ((gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(RadioModifier))) && (strcmp(TextModifier,"") == 0))
    {
        Resultat = 0;
    }
    else if ((gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(RadioSupprimer))))
    {
        Resultat = 0;
    }
    else
    {
        Resultat = 1;
    }

    if (Resultat == 0)
    {
        ClearGererClasse();
        RemplissageListDesClasses(Emplacement);
        gtk_widget_hide(window4);
        gtk_widget_show(window1);
    }

    else
    {

        GtkWidget *pRetour;

        gchar* sUtf8 = 0;
        gchar* bUtf8 = 0;

        bUtf8 = g_locale_from_utf8("Vous avez fait des changements qui ne sont pas encore enregistrer \nVoulez-vous vraiment retourner à la page d'accueil ?", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);



        pRetour = gtk_message_dialog_new (GTK_WINDOW(window4),
                                          GTK_DIALOG_MODAL,
                                          GTK_MESSAGE_QUESTION,
                                          GTK_BUTTONS_YES_NO,
                                          sUtf8);

        switch(gtk_dialog_run(GTK_DIALOG(pRetour)))
        {
        case GTK_RESPONSE_YES:
            gtk_widget_destroy(pRetour);
            ClearGererClasse();
            RemplissageListDesClasses(Emplacement);
            gtk_widget_hide(window4);
            gtk_widget_show(window1);
            break;
        case GTK_RESPONSE_NO:
            gtk_widget_destroy(pRetour);
            break;
        }
        g_free(bUtf8);
        g_free(sUtf8);
    }

}

G_MODULE_EXPORT void on_BtnGererClasses_clicked(GtkButton *b)
{

    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(RadioAjouter),  (gboolean) TRUE);
    gtk_widget_show(frame2);

    gtk_widget_show(window4);
    gtk_widget_hide(window1);

}


G_MODULE_EXPORT void on_RadioAjouter_toggled(GtkRadioButton *b)
{

    gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
    if (T)
    {
        gtk_widget_show(frame2);
    }
    else
    {
        ClearGererClasse();
        gtk_widget_hide(frame2);
    }

}

G_MODULE_EXPORT void on_RadioModifier_toggled(GtkRadioButton *b)
{

    char Emplacement[MAXCHARS] = {"Gerer-Modifier"};

    gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
    if (T)
    {
        RemplissageListDesClasses(Emplacement);
        gtk_widget_show(frame3);
    }
    else
    {
        ClearGererClasse();
        gtk_widget_hide(frame3);
    }

}

G_MODULE_EXPORT void on_RadioSupprimer_toggled(GtkRadioButton *b)
{

    char Emplacement[MAXCHARS] = {"Gerer-Supprimer"};

    gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
    if (T)
    {
        RemplissageListDesClasses(Emplacement);
        gtk_widget_show(frame4);
    }
    else
    {
        ClearGererClasse();
        gtk_widget_hide(frame4);
    }

}

void ClearGererClasse()
{

    char AjouterClasse[MAXCHARS];
    char ModifierClasse[MAXCHARS];

    AjouterClasse[0]=0;
    ModifierClasse[0]=0;

    gtk_entry_set_text(GTK_ENTRY(entryAjouterClasse),(const gchar*) AjouterClasse);
    gtk_entry_set_text(GTK_ENTRY(entryModifierClasse),(const gchar*) ModifierClasse);

    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(ComboModifierClasse));
    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(comboSupprimer));

}

G_MODULE_EXPORT void on_buttonQuitter4_clicked(GtkButton *b)
{

    GtkWidget *pQuitter;

    pQuitter = gtk_message_dialog_new (GTK_WINDOW(window4),
                                       GTK_DIALOG_MODAL,
                                       GTK_MESSAGE_QUESTION,
                                       GTK_BUTTONS_YES_NO,
                                       "Voulez-vous vraiment\nquitter le programme?");

    switch(gtk_dialog_run(GTK_DIALOG(pQuitter)))
    {
    case GTK_RESPONSE_YES:
        gtk_main_quit();
        break;
    case GTK_RESPONSE_NO:
        gtk_widget_destroy(pQuitter);
        break;
    }

}

G_MODULE_EXPORT void on_buttonSaveGererClasse_clicked(GtkButton *b)
{

    const gchar *TextAjouter;
    const gchar *TextModifier;
    GtkWidget *pErreur;
    gchar* ValueModifier = 0;
    gchar* ValueSupprimer = 0;
    gchar* sUtf8 = 0;
    gchar* bUtf8 = 0;

    TextAjouter = gtk_entry_get_text(GTK_ENTRY(entryAjouterClasse));
    TextModifier = gtk_entry_get_text(GTK_ENTRY(entryModifierClasse));


    ValueModifier = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(comboModifier));
    ValueSupprimer = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(comboSupprimer));


    if ((gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(RadioAjouter))) && (strcmp(TextAjouter,"")!=0))
    {

        AjouterClasse();

    }
    else if ((gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(RadioAjouter))) && (strcmp(TextAjouter,"")==0))
    {


        bUtf8 = g_locale_from_utf8(" S'il vous plaît Entrer le Nom de la Classe à Ajouter ! ", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);


        pErreur = gtk_message_dialog_new (GTK_WINDOW(window4),
                                          GTK_DIALOG_MODAL,
                                          GTK_MESSAGE_ERROR,
                                          GTK_BUTTONS_OK,
                                          sUtf8);


        gtk_dialog_run(GTK_DIALOG(pErreur));

        gtk_widget_destroy(pErreur);
        g_free(bUtf8);
        g_free(sUtf8);


    }
    else if ((gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(RadioModifier))) && ((strcmp(TextModifier,"") == 0) || (ValueModifier == NULL) ))
    {

        bUtf8 = g_locale_from_utf8(" S'il vous plaît Selectionnez La classe puis Entrer \nle Nouveau Nom de la Classe avant de continuer ! ", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);

        pErreur = gtk_message_dialog_new (GTK_WINDOW(window4),
                                          GTK_DIALOG_MODAL,
                                          GTK_MESSAGE_ERROR,
                                          GTK_BUTTONS_OK,
                                          sUtf8);

        gtk_dialog_run(GTK_DIALOG(pErreur));

        gtk_widget_destroy(pErreur);
        g_free(bUtf8);
        g_free(sUtf8);


    }
    else if ((gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(RadioModifier))) && ((strcmp(TextModifier,"") != 0) && (ValueModifier != NULL) ))
    {

        ModifierClasse();

    }
    else if ((gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(RadioSupprimer))) && ValueSupprimer != NULL )
    {

        SupprimerClasse();

    }
    else if ((gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(RadioSupprimer))) && ValueSupprimer == NULL )
    {

        bUtf8 = g_locale_from_utf8(" S'il vous plaît Selectionné d'abord une classe pour la Supprimer! ", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);

        pErreur = gtk_message_dialog_new (GTK_WINDOW(window4),
                                          GTK_DIALOG_MODAL,
                                          GTK_MESSAGE_ERROR,
                                          GTK_BUTTONS_OK,
                                          sUtf8);

        gtk_dialog_run(GTK_DIALOG(pErreur));

        gtk_widget_destroy(pErreur);
        g_free(bUtf8);
        g_free(sUtf8);

    }
    else
    {


        pErreur = gtk_message_dialog_new (GTK_WINDOW(window4),
                                          GTK_DIALOG_MODAL,
                                          GTK_MESSAGE_ERROR,
                                          GTK_BUTTONS_OK,
                                          " Une erreur s'est produit ! "
                                         );


        gtk_dialog_run(GTK_DIALOG(pErreur));

        gtk_widget_destroy(pErreur);

    }

}

void AjouterClasse()
{

    char NomDeClasse[MAXCHARS],ClasseTXT[MAXCHARS];
    const gchar *TextAjouter;
    int Resultat = 0;


    TextAjouter = gtk_entry_get_text(GTK_ENTRY(entryAjouterClasse));

    strcpy(NomDeClasse,TextAjouter);


    for (int i = 0; NomDeClasse[i]!='\0'; i++)
    {
        if(NomDeClasse[i] == Espace)
        {
            NomDeClasse[i] = Tiret;
        }
    }


    for (int i = 0; NomDeClasse[i]!='\0'; i++)
    {

        if(NomDeClasse[i] >= 'a' && NomDeClasse[i] <= 'z')
        {

            NomDeClasse[i] = NomDeClasse[i] - 32;

        }
    }


    strcpy(ClasseTXT,DossierDeTravail);
    strcat(ClasseTXT,"\\Classes.txt");

    SupprimerLigneVide(NomDeClasse);

    char chaine[MAXCHARS];

    FILE* fichier;

    fichier = fopen(ClasseTXT, "r");
    Resultat = 0;

    if (fichier != NULL)
    {

        while(fgets(chaine,1000,fichier) != NULL)
        {

            SupprimerLigneVide(chaine);

            if(strcmp(chaine,NomDeClasse)==0)
            {

                Resultat = 1;

            }
        }

        fclose(fichier);
    }

    if(Resultat == 1)
    {

        GtkWidget *pErreur;

        gchar* sUtf8 = 0;
        gchar* bUtf8 = 0;

        bUtf8 = g_locale_from_utf8(" Classe éxiste Déja avec un même \n Nom s'il vous plaît choisissais un autre nom ! ", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);


        pErreur = gtk_message_dialog_new (GTK_WINDOW(window4),
                                          GTK_DIALOG_MODAL,
                                          GTK_MESSAGE_ERROR,
                                          GTK_BUTTONS_OK,
                                          sUtf8);

        gtk_dialog_run(GTK_DIALOG(pErreur));

        gtk_widget_destroy(pErreur);
        g_free(bUtf8);
        g_free(sUtf8);


    }
    else if (Resultat == 0)
    {

        int Reponse = 0;

        char Message[MAXCHARS];

        strcpy(Message, " Voulez-vous vraiment Créer Une \n Classe avec le nom '");
        strcat(Message, TextAjouter);
        strcat(Message, "' ? ");

        gchar* sUtf8 = 0;
        gchar* bUtf8 = 0;

        bUtf8 = g_locale_from_utf8(Message, -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);


        GtkWidget *pAttention;

        pAttention = gtk_message_dialog_new (GTK_WINDOW(window4),
                                             GTK_DIALOG_MODAL,
                                             GTK_MESSAGE_QUESTION,
                                             GTK_BUTTONS_YES_NO,
                                             sUtf8);

        switch(gtk_dialog_run(GTK_DIALOG(pAttention)))
        {
        case GTK_RESPONSE_YES:
            Reponse = 1;
            gtk_widget_destroy(pAttention);
            break;
        case GTK_RESPONSE_NO:
            Reponse = 0;
            gtk_widget_destroy(pAttention);
            break;
        }
        g_free(bUtf8);
        g_free(sUtf8);

        if (Reponse == 1)
        {

            char CreerDossier[MAXCHARS], EleveTXT[MAXCHARS];

            strcpy(CreerDossier,DossierDeTravail);
            strcat(CreerDossier,"\\");
            strcat(CreerDossier,NomDeClasse);
            strcpy(EleveTXT,CreerDossier);
            strcat(EleveTXT,"\\");
            strcat(EleveTXT,"eleves.txt");

            mkdir(CreerDossier);

            FILE* Creation;

            Creation = fopen(EleveTXT,"w");

            if (Creation != NULL)
            {

                fclose(Creation);

            }

            FILE* AddToClasseTXT;

            AddToClasseTXT = fopen(ClasseTXT, "a");

            if (AddToClasseTXT != NULL)
            {

                fprintf(AddToClasseTXT,"%s\n",NomDeClasse);

                fclose(AddToClasseTXT);

            }

            GtkWidget *pSuccess;

            gchar* sUtf8 = 0;
            gchar* bUtf8 = 0;

            bUtf8 = g_locale_from_utf8(" Classe Créer Avec succès! ", -1, NULL, NULL, NULL);

            sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);

            pSuccess = gtk_message_dialog_new (GTK_WINDOW(window4),
                                               GTK_DIALOG_MODAL,
                                               GTK_MESSAGE_INFO,
                                               GTK_BUTTONS_OK,
                                               sUtf8);


            gtk_dialog_run(GTK_DIALOG(pSuccess));

            gtk_widget_destroy(pSuccess);

            g_free(bUtf8);
            g_free(sUtf8);

            ClearGererClasse();


        }
        else if(Reponse == 0)
        {

            GtkWidget *pRien;

            gchar* sUtf8 = 0;
            gchar* bUtf8 = 0;

            bUtf8 = g_locale_from_utf8(" La Classe n'as pas étè Créer! ", -1, NULL, NULL, NULL);

            sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);


            pRien = gtk_message_dialog_new (GTK_WINDOW(window4),
                                            GTK_DIALOG_MODAL,
                                            GTK_MESSAGE_INFO,
                                            GTK_BUTTONS_OK,
                                            sUtf8);

            gtk_dialog_run(GTK_DIALOG(pRien));

            gtk_widget_destroy(pRien);
            g_free(bUtf8);
            g_free(sUtf8);


        }


    }


    Resultat = 0;

}

void SupprimerClasse()
{


    char NomDeClasse[MAXCHARS],ClasseTXT[MAXCHARS], Emplacement[] = {"Gerer-Supprimer"};
    const gchar *TextAjouter;
    int Resultat = 0;


    TextAjouter = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(comboSupprimer));

    strcpy(NomDeClasse,TextAjouter);


    for (int i = 0; NomDeClasse[i]!='\0'; i++)
    {
        if(NomDeClasse[i] == Espace)
        {
            NomDeClasse[i] = Tiret;
        }
    }


    for (int i = 0; NomDeClasse[i]!='\0'; i++)
    {

        if(NomDeClasse[i] >= 'a' && NomDeClasse[i] <= 'z')
        {

            NomDeClasse[i] = NomDeClasse[i] - 32;

        }
    }


    strcpy(ClasseTXT,DossierDeTravail);
    strcat(ClasseTXT,"\\Classes.txt");

    SupprimerLigneVide(NomDeClasse);

    char chaine[MAXCHARS];

    FILE* fichier;

    fichier = fopen(ClasseTXT, "r");
    Resultat = 0;

    if (fichier != NULL)
    {

        while(fgets(chaine,1000,fichier) != NULL)
        {

            SupprimerLigneVide(chaine);

            if(strcmp(chaine,NomDeClasse)==0)
            {

                Resultat = 1;

            }
        }

        fclose(fichier);
    }

    if(Resultat == 0)
    {

        GtkWidget *pErreur;

        gchar* sUtf8 = 0;
        gchar* bUtf8 = 0;

        bUtf8 = g_locale_from_utf8(" Aucune Classe Existe avec ce Nom\n S'il vous plaît Entrer le nom d'une Classe Qui Existe! ", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);


        pErreur = gtk_message_dialog_new (GTK_WINDOW(window4),
                                          GTK_DIALOG_MODAL,
                                          GTK_MESSAGE_ERROR,
                                          GTK_BUTTONS_OK,
                                          sUtf8);

        gtk_dialog_run(GTK_DIALOG(pErreur));

        gtk_widget_destroy(pErreur);
        g_free(bUtf8);
        g_free(sUtf8);


    }
    else if (Resultat == 1)
    {

        int Reponse = 0;
        char Message[MAXCHARS];

        strcpy(Message, " Voulez-vous vraiment Supprimer \n la Classe '");
        strcat(Message, TextAjouter);
        strcat(Message, "' ? ");

        GtkWidget *pAttention;

        pAttention = gtk_message_dialog_new (GTK_WINDOW(window4),
                                             GTK_DIALOG_MODAL,
                                             GTK_MESSAGE_QUESTION,
                                             GTK_BUTTONS_YES_NO,
                                             Message);

        switch(gtk_dialog_run(GTK_DIALOG(pAttention)))
        {
        case GTK_RESPONSE_YES:
            Reponse = 1;
            gtk_widget_destroy(pAttention);
            break;
        case GTK_RESPONSE_NO:
            Reponse = 0;
            gtk_widget_destroy(pAttention);
            break;
        }

        if(Reponse == 1)
        {

            char SupprimerDossierClasse[MAXCHARS], EleveTXT[MAXCHARS], TMPALLTXT[MAXCHARS], Ligne[MAXCHARS];

            strcpy(SupprimerDossierClasse,DossierDeTravail);
            strcat(SupprimerDossierClasse,"\\");

            strcpy(TMPALLTXT,SupprimerDossierClasse);
            strcat(TMPALLTXT,"tmp.txt");

            strcat(SupprimerDossierClasse,NomDeClasse);


            strcpy(EleveTXT,SupprimerDossierClasse);
            strcat(EleveTXT,"\\");
            strcat(EleveTXT,"eleves.txt");



            CopyFile(ClasseTXT,TMPALLTXT,0);


            FILE* RemoveFromClasseTXT;

            RemoveFromClasseTXT = fopen(ClasseTXT, "w");

            FILE* ReadFrom = NULL;
            ReadFrom = fopen(TMPALLTXT,"r");


            if (RemoveFromClasseTXT != NULL)
            {

                if(ReadFrom != NULL)
                {
                    while(fgets(Ligne,1000,ReadFrom) != NULL)
                    {
                        SupprimerLigneVide(Ligne);

                        if(strcmp(Ligne,NomDeClasse)!=0)
                        {

                            fprintf(RemoveFromClasseTXT,"%s\n",Ligne);

                        }

                    }

                    // remove((const char*) TMPALLTXT);

                    fclose(ReadFrom);
                }

                fclose(RemoveFromClasseTXT);

            }

            char Commande[MAXCHARS], Commande2[MAXCHARS];

            strcpy(Commande,"rmdir /Q /S \"");
            strcat(Commande,SupprimerDossierClasse);
            strcat(Commande,"\"");

            strcpy(Commande2,"del /F /Q \"");
            strcat(Commande2,TMPALLTXT);
            strcat(Commande2,"\"");

            system(Commande);
            // system(Commande2);

            remove(TMPALLTXT);


            GtkWidget *pSuccess;

            gchar* sUtf8 = 0;
            gchar* bUtf8 = 0;

            bUtf8 = g_locale_from_utf8( " Classe Supprimer Avec succès! ", -1, NULL, NULL, NULL);

            sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);

            pSuccess = gtk_message_dialog_new (GTK_WINDOW(window4),
                                               GTK_DIALOG_MODAL,
                                               GTK_MESSAGE_INFO,
                                               GTK_BUTTONS_OK,
                                               sUtf8);

            gtk_dialog_run(GTK_DIALOG(pSuccess));

            gtk_widget_destroy(pSuccess);

            g_free(bUtf8);
            g_free(sUtf8);

            ClearGererClasse();

            RemplissageListDesClasses(Emplacement);


        }
        else if(Reponse == 0)
        {

            GtkWidget *pRien;

            gchar* sUtf8 = 0;
            gchar* bUtf8 = 0;

            bUtf8 = g_locale_from_utf8(" La Classe n'as pas étè supprimer! ", -1, NULL, NULL, NULL);

            sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);


            pRien = gtk_message_dialog_new (GTK_WINDOW(window4),
                                            GTK_DIALOG_MODAL,
                                            GTK_MESSAGE_INFO,
                                            GTK_BUTTONS_OK,
                                            sUtf8);

            gtk_dialog_run(GTK_DIALOG(pRien));

            gtk_widget_destroy(pRien);
            g_free(bUtf8);
            g_free(sUtf8);

        }

    }

    Resultat = 0;
}


void ModifierClasse()
{



    char NomDeClasseExistant[MAXCHARS], NomDeClasseARemplacer[MAXCHARS],ClasseTXT[MAXCHARS], Emplacement[] = {"Gerer-Modifier"};
    const gchar *TextExiste;
    const gchar *TextARemplacer;
    int Resultat = 0, Existe = 0;


    TextExiste= gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(comboModifier));
    TextARemplacer = gtk_entry_get_text(GTK_ENTRY(entryModifierClasse));

    strcpy(NomDeClasseExistant,TextExiste);
    strcpy(NomDeClasseARemplacer,TextARemplacer);


    for (int i = 0; NomDeClasseExistant[i]!='\0'; i++)
    {
        if(NomDeClasseExistant[i] == Espace)
        {
            NomDeClasseExistant[i] = Tiret;
        }
    }


    for (int i = 0; NomDeClasseExistant[i]!='\0'; i++)
    {

        if(NomDeClasseExistant[i] >= 'a' && NomDeClasseExistant[i] <= 'z')
        {

            NomDeClasseExistant[i] = NomDeClasseExistant[i] - 32;

        }
    }

    for (int i = 0; NomDeClasseARemplacer[i]!='\0'; i++)
    {
        if(NomDeClasseARemplacer[i] == Espace)
        {
            NomDeClasseARemplacer[i] = Tiret;
        }
    }


    for (int i = 0; NomDeClasseARemplacer[i]!='\0'; i++)
    {

        if(NomDeClasseARemplacer[i] >= 'a' && NomDeClasseARemplacer[i] <= 'z')
        {

            NomDeClasseARemplacer[i] = NomDeClasseARemplacer[i] - 32;

        }
    }

    strcpy(ClasseTXT,DossierDeTravail);
    strcat(ClasseTXT,"\\Classes.txt");

    SupprimerLigneVide(NomDeClasseExistant);

    char chaine[MAXCHARS];

    FILE* fichier;

    fichier = fopen(ClasseTXT, "r");
    Resultat = 0;
    Existe = 0;

    if (fichier != NULL)
    {

        while(fgets(chaine,1000,fichier) != NULL)
        {

            SupprimerLigneVide(chaine);

            if(strcmp(chaine,NomDeClasseExistant)==0)
            {

                Resultat = 1;

            }

            if(strcmp(chaine,NomDeClasseARemplacer)==0)
            {

                Existe = 1;

            }

        }

        fclose(fichier);
    }

    if(Resultat == 0)
    {

        GtkWidget *pErreur;

        gchar* sUtf8 = 0;
        gchar* bUtf8 = 0;

        bUtf8 = g_locale_from_utf8(" Aucune Classe n'éxiste avec ce Nom\n S'il vous plaît Entrer le nom d'une Classe Qui éxiste ! ", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);


        pErreur = gtk_message_dialog_new (GTK_WINDOW(window4),
                                          GTK_DIALOG_MODAL,
                                          GTK_MESSAGE_ERROR,
                                          GTK_BUTTONS_OK,
                                          sUtf8);


        gtk_dialog_run(GTK_DIALOG(pErreur));

        gtk_widget_destroy(pErreur);

        g_free(bUtf8);
        g_free(sUtf8);


    }
    else if (Resultat == 1)
    {
        if (Existe == 1)
        {

            GtkWidget *pExiste;
            gchar* sUtf8 = 0;
            gchar* bUtf8 = 0;

            bUtf8 = g_locale_from_utf8(" Attention! Une classe Existe déjà avec le même nom \n S'il vous plaît choisissais un autre ", -1, NULL, NULL, NULL);

            sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);


            pExiste = gtk_message_dialog_new (GTK_WINDOW(window4),
                                              GTK_DIALOG_MODAL,
                                              GTK_MESSAGE_ERROR,
                                              GTK_BUTTONS_OK,
                                              sUtf8);


            gtk_dialog_run(GTK_DIALOG(pExiste));

            gtk_widget_destroy(pExiste);

            g_free(bUtf8);
            g_free(sUtf8);



        }
        else if (Existe == 0)
        {

            int Reponse = 0;
            char Message[MAXCHARS];

            strcpy(Message, " Voulez-vous vraiment Modifier \n la Classe '");
            strcat(Message, TextExiste);
            strcat(Message, "' par '");
            strcat(Message, TextARemplacer);
            strcat(Message, "' ? ");

            GtkWidget *pAttention;

            pAttention = gtk_message_dialog_new (GTK_WINDOW(window4),
                                                 GTK_DIALOG_MODAL,
                                                 GTK_MESSAGE_QUESTION,
                                                 GTK_BUTTONS_YES_NO,
                                                 Message);

            switch(gtk_dialog_run(GTK_DIALOG(pAttention)))
            {
            case GTK_RESPONSE_YES:
                Reponse = 1;
                gtk_widget_destroy(pAttention);
                break;
            case GTK_RESPONSE_NO:
                Reponse = 0;
                gtk_widget_destroy(pAttention);
                break;
            }

            if(Reponse == 1)
            {

                char DeplacerDossierDe[MAXCHARS], DeplacerDossierVers[MAXCHARS], TMPALLTXT[MAXCHARS], Ligne[MAXCHARS];

                strcpy(DeplacerDossierDe,DossierDeTravail);
                strcat(DeplacerDossierDe,"\\");
                strcpy(TMPALLTXT,DeplacerDossierDe);
                strcat(TMPALLTXT,"tmp.txt");
                strcat(DeplacerDossierDe,"\\");
                strcpy(DeplacerDossierVers,DeplacerDossierDe);
                strcat(DeplacerDossierDe,NomDeClasseExistant);
                strcat(DeplacerDossierVers,NomDeClasseARemplacer);

                rename(DeplacerDossierDe,DeplacerDossierVers);

                CopyFile(ClasseTXT,TMPALLTXT,0);


                FILE* RenameFromClasseTXT;

                RenameFromClasseTXT = fopen(ClasseTXT, "w");

                FILE* ReadFrom = NULL;
                ReadFrom = fopen(TMPALLTXT,"r");

                if (RenameFromClasseTXT != NULL)
                {

                    if(ReadFrom != NULL)
                    {

                        while(fgets(Ligne,1000,ReadFrom) != NULL)
                        {

                            SupprimerLigneVide(Ligne);

                            if(strcmp(Ligne,NomDeClasseExistant)!=0)
                            {

                                fprintf(RenameFromClasseTXT,"%s\n",Ligne);

                            }
                            else if(strcmp(Ligne,NomDeClasseExistant)==0)
                            {

                                fprintf(RenameFromClasseTXT,"%s\n",NomDeClasseARemplacer);

                            }

                        }

                        fclose(ReadFrom);
                    }

                    fclose(RenameFromClasseTXT);

                }

                GtkWidget *pSuccess;

                gchar* sUtf8 = 0;
                gchar* bUtf8 = 0;

                remove((const char* ) TMPALLTXT);


                bUtf8 = g_locale_from_utf8(" Classe Modifié Avec succès! ", -1, NULL, NULL, NULL);

                sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);

                pSuccess = gtk_message_dialog_new (GTK_WINDOW(window4),
                                                   GTK_DIALOG_MODAL,
                                                   GTK_MESSAGE_INFO,
                                                   GTK_BUTTONS_OK,
                                                   sUtf8);


                gtk_dialog_run(GTK_DIALOG(pSuccess));

                gtk_widget_destroy(pSuccess);

                g_free(bUtf8);
                g_free(sUtf8);

                ClearGererClasse();

                RemplissageListDesClasses(Emplacement);


            }
            else if(Reponse == 0)
            {

                GtkWidget *pRien;
                gchar* sUtf8 = 0;
                gchar* bUtf8 = 0;

                bUtf8 = g_locale_from_utf8(" La Classe n'as pas étè Modifier ! ", -1, NULL, NULL, NULL);

                sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);


                pRien = gtk_message_dialog_new (GTK_WINDOW(window4),
                                                GTK_DIALOG_MODAL,
                                                GTK_MESSAGE_INFO,
                                                GTK_BUTTONS_OK,
                                                sUtf8);

                gtk_dialog_run(GTK_DIALOG(pRien));

                gtk_widget_destroy(pRien);

                g_free(bUtf8);
                g_free(sUtf8);

            }

        }
    }

    Resultat = 0;
    Existe = 0;


}

void Chargement()
{

    gdouble dFraction;
    gint i;
    gint iTotal = 2000;
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(pbar1), 0.0);

    gtk_grab_add(pbar1);

    for(i = 0 ; i < iTotal ; ++i)
    {
        dFraction = (gdouble)i / (gdouble)iTotal;

        gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(pbar1), dFraction);

        gtk_main_iteration();
    }

    gtk_grab_remove(pbar1);

    Check_Lock();


}

G_MODULE_EXPORT void on_window5_show(GtkWindow *w)
{

    Chargement();

}

void Check_Lock()
{

    if (PassEnabled == 1)
    {
        gtk_widget_hide(window5);
        gtk_widget_show(window6);
    }
    else
    {
        gtk_widget_hide(window5);
        gtk_widget_show(window1);
    }

}


G_MODULE_EXPORT void on_buttonQuitter6_clicked(GtkButton *b)
{

    GtkWidget *pQuitter;

    pQuitter = gtk_message_dialog_new (GTK_WINDOW(window6),
                                       GTK_DIALOG_MODAL,
                                       GTK_MESSAGE_QUESTION,
                                       GTK_BUTTONS_YES_NO,
                                       "Voulez-vous vraiment\nquitter le programme?");

    switch(gtk_dialog_run(GTK_DIALOG(pQuitter)))
    {
    case GTK_RESPONSE_YES:
        gtk_main_quit();
        break;
    case GTK_RESPONSE_NO:
        gtk_widget_destroy(pQuitter);
        break;
    }

}


G_MODULE_EXPORT void on_entryPass_activate(GtkEntry *e)
{

    VerifierPass();
}


G_MODULE_EXPORT void on_buttonContinuer6_clicked(GtkButton *b)
{

    VerifierPass();

}

void VerifierPass()
{

    char EntreePass[MAXCHARS];
    const gchar *PasswordEntrer;


    PasswordEntrer = gtk_entry_get_text(GTK_ENTRY(entryPass));
    strcpy(EntreePass,PasswordEntrer);


    if (strcmp(EntreePass,"") == 0 )
    {

        GtkWidget *Vide;

        gchar* sUtf8 = 0;
        gchar* bUtf8 = 0;

        bUtf8 = g_locale_from_utf8(" Entrer un mot de passe s'il veut plaît! ", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);


        Vide = gtk_message_dialog_new (GTK_WINDOW(window6),
                                       GTK_DIALOG_MODAL,
                                       GTK_MESSAGE_ERROR,
                                       GTK_BUTTONS_OK,
                                       sUtf8);

        gtk_dialog_run(GTK_DIALOG(Vide));

        gtk_widget_destroy(Vide);

        g_free(bUtf8);
        g_free(sUtf8);

    }
    else
    {

        if (strcmp(EntreePass,PassFromFile) == 0 )
        {

            gtk_widget_hide(window6);
            gtk_widget_show(window1);

        }
        else
        {

            GtkWidget *Incorrecte;
            char ClearEntry[MAXCHARS];
            ClearEntry[0]=0;


            Incorrecte = gtk_message_dialog_new (GTK_WINDOW(window6),
                                                 GTK_DIALOG_MODAL,
                                                 GTK_MESSAGE_ERROR,
                                                 GTK_BUTTONS_OK,
                                                 " Mot de passe Incorrect! "
                                                );

            gtk_dialog_run(GTK_DIALOG(Incorrecte));

            gtk_widget_destroy(Incorrecte);

            gtk_entry_set_text(GTK_ENTRY(entryPass), (const gchar* ) ClearEntry);

        }
    }



}

G_MODULE_EXPORT void on_BtnApropos_clicked(GtkButton *b)
{

    gtk_widget_hide(window1);
    gtk_widget_show(window7);

}

G_MODULE_EXPORT void on_buttonRetour7_clicked(GtkButton *b)
{
    gtk_widget_hide(window7);
    gtk_widget_show(window1);

}



static void activate_switchAppLock(GObject *switcher,GParamSpec *pspec, gpointer user_data)
{

    if (gtk_switch_get_active (GTK_SWITCH (switcher)))
    {
        if(strcmp(PassFromFile,"Nothing")==0)
        {
            PassEnabled = 0;
            SetIDAndPass();

            GtkWidget *Incorrecte;

            gchar* sUtf8 = 0;
            gchar* bUtf8 = 0;

            bUtf8 = g_locale_from_utf8(" Veuillez Entrer Un mot de passe D'abord dans la fenêtre des paramétres! ", -1, NULL, NULL, NULL);

            sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);


            Incorrecte = gtk_message_dialog_new (GTK_WINDOW(window1),
                                                 GTK_DIALOG_MODAL,
                                                 GTK_MESSAGE_ERROR,
                                                 GTK_BUTTONS_OK,
                                                 sUtf8);

            gtk_dialog_run(GTK_DIALOG(Incorrecte));

            gtk_widget_destroy(Incorrecte);

            g_free(bUtf8);
            g_free(sUtf8);

            gtk_switch_set_active(GTK_SWITCH(switchAppLock), (gboolean) FALSE);


        }
        else
        {
            PassEnabled = 1;
            SetIDAndPass();
        }
    }
    else
    {
        PassEnabled = 0;
        SetIDAndPass();
    }

}


G_MODULE_EXPORT void on_BtnParametre_clicked(GtkButton *b)
{

    char EntreeVide1[MAXCHARS];

    EntreeVide1[0] = 0;

    GetIdAndPass();

    if(strcmp(PassFromFile,"Nothing")==0)
    {

        gtk_widget_hide(label77);
        gtk_widget_hide(entryPassActuelle);
        gtk_widget_hide(buttonAfficherPass);

        gtk_widget_hide(window1);
        gtk_widget_show(window8);

        gtk_button_set_label(GTK_BUTTON(buttonAfficherPass), (const gchar*) " Afficher");
        gtk_button_set_label(GTK_BUTTON(buttonAffihcerPassEntrer), (const gchar*) " Afficher");

        gtk_entry_set_text(GTK_ENTRY(entryNouveauPass), (const gchar*) EntreeVide1);
        gtk_entry_set_text(GTK_ENTRY(entryConfirmerPass), (const gchar*) EntreeVide1);

        gtk_entry_set_visibility(GTK_ENTRY(entryPassActuelle),(gboolean) FALSE);
        gtk_entry_set_visibility(GTK_ENTRY(entryNouveauPass),(gboolean) FALSE);
        gtk_entry_set_visibility(GTK_ENTRY(entryConfirmerPass),(gboolean) FALSE);

        AffPass = 0;
        PassEntrer = 0;


    }
    else if(strcmp(PassFromFile,"Nothing") != 0)
    {

        gtk_widget_show(label77);
        gtk_widget_show(entryPassActuelle);
        gtk_widget_show(buttonAfficherPass);
        gtk_button_set_label(GTK_BUTTON(buttonAfficherPass), (const gchar*) " Afficher");
        gtk_button_set_label(GTK_BUTTON(buttonAffihcerPassEntrer), (const gchar*) " Afficher");


        gtk_entry_set_text(GTK_ENTRY(entryNouveauPass), (const gchar*) EntreeVide1);
        gtk_entry_set_text(GTK_ENTRY(entryConfirmerPass), (const gchar*) EntreeVide1);

        gtk_entry_set_text(GTK_ENTRY(entryPassActuelle), (const gchar* ) PassFromFile);
        gtk_entry_set_visibility(GTK_ENTRY(entryPassActuelle),(gboolean) FALSE);
        gtk_entry_set_visibility(GTK_ENTRY(entryNouveauPass),(gboolean) FALSE);
        gtk_entry_set_visibility(GTK_ENTRY(entryConfirmerPass),(gboolean) FALSE);


        AffPass = 0;
        PassEntrer = 0;


        gtk_widget_hide(window1);
        gtk_widget_show(window8);

    }


}


G_MODULE_EXPORT void on_buttonRetourPass_clicked(GtkButton *b)
{


    char EntreeVide1[MAXCHARS], EntreeVide2[MAXCHARS];
    const gchar *Entree1;
    const gchar *Entree2;

    EntreeVide1[0]=0;
    EntreeVide2[0]=0;

    Entree1 = gtk_entry_get_text(GTK_ENTRY(entryNouveauPass));
    Entree2 = gtk_entry_get_text(GTK_ENTRY(entryConfirmerPass));


    if ((strcmp(EntreeVide1,Entree1)==0) && (strcmp(EntreeVide2,Entree2)==0))
    {

        gtk_widget_hide(window8);
        gtk_widget_show(window1);


    }
    else
    {


        GtkWidget *pChangement;

        gchar* sUtf8 = 0;
        gchar* bUtf8 = 0;

        bUtf8 = g_locale_from_utf8(" Vous avez faites des changement qui ne sont pas encore sauvegarder \n Voulez-vous vraiment retourner à la page d'accueil ? ", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);


        pChangement = gtk_message_dialog_new (GTK_WINDOW(window8),
                                              GTK_DIALOG_MODAL,
                                              GTK_MESSAGE_QUESTION,
                                              GTK_BUTTONS_YES_NO,
                                              sUtf8);

        switch(gtk_dialog_run(GTK_DIALOG(pChangement)))
        {
        case GTK_RESPONSE_YES:
            gtk_widget_hide(window8);
            gtk_widget_show(window1);
            gtk_widget_destroy(pChangement);
            break;
        case GTK_RESPONSE_NO:
            gtk_widget_destroy(pChangement);
            break;
        }

        g_free(bUtf8);
        g_free(sUtf8);

    }


}


G_MODULE_EXPORT void on_buttonAfficherPass_clicked(GtkButton *b)
{

    if(AffPass == 0)
    {

        gtk_entry_set_visibility(GTK_ENTRY(entryPassActuelle),(gboolean) TRUE);
        gtk_button_set_label(GTK_BUTTON(buttonAfficherPass), (const gchar*) " Cacher");
        AffPass = 1;

    }
    else if (AffPass == 1)
    {

        gtk_entry_set_visibility(GTK_ENTRY(entryPassActuelle),(gboolean) FALSE);
        gtk_button_set_label(GTK_BUTTON(buttonAfficherPass), (const gchar*) " Afficher");
        AffPass = 0;

    }


}

G_MODULE_EXPORT void on_buttonAffihcerPassEntrer_clicked(GtkButton *b)
{


    if(PassEntrer == 0)
    {

        gtk_entry_set_visibility(GTK_ENTRY(entryNouveauPass),(gboolean) TRUE);
        gtk_entry_set_visibility(GTK_ENTRY(entryConfirmerPass),(gboolean) TRUE);
        gtk_button_set_label(GTK_BUTTON(buttonAffihcerPassEntrer), (const gchar*) " Cacher");

        PassEntrer = 1;

    }
    else if (PassEntrer == 1)
    {

        gtk_entry_set_visibility(GTK_ENTRY(entryNouveauPass),(gboolean) FALSE);
        gtk_entry_set_visibility(GTK_ENTRY(entryConfirmerPass),(gboolean) FALSE);
        gtk_button_set_label(GTK_BUTTON(buttonAffihcerPassEntrer), (const gchar*) " Afficher");

        PassEntrer = 0;

    }

}


G_MODULE_EXPORT void on_buttonEnregistrerPass_clicked(GtkButton *b)
{

    char EntreeVide1[MAXCHARS], EntreeVide2[MAXCHARS];
    const gchar *Entree1;
    const gchar *Entree2;
    GtkWidget *pInfo;


    EntreeVide1[0]=0;
    EntreeVide2[0]=0;

    Entree1 = gtk_entry_get_text(GTK_ENTRY(entryNouveauPass));
    Entree2 = gtk_entry_get_text(GTK_ENTRY(entryConfirmerPass));


    if ((strcmp(EntreeVide1,Entree1)==0) && (strcmp(EntreeVide2,Entree2)==0))
    {
        int Resultat = 0;


        Resultat = MDPvide();

        if (Resultat == 0)
        {

            PassEnabled = 0;
            strcpy(PassFromFile,(const gchar*) "Nothing");

            SetIDAndPass();

            gchar* sUtf8 = 0;
            gchar* bUtf8 = 0;

            bUtf8 = g_locale_from_utf8(" Mot de passe désactivé avec succès ", -1, NULL, NULL, NULL);

            sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);


            pInfo = gtk_message_dialog_new (GTK_WINDOW(window8),
                                            GTK_DIALOG_MODAL,
                                            GTK_MESSAGE_INFO,
                                            GTK_BUTTONS_OK,
                                            sUtf8);

            gtk_dialog_run(GTK_DIALOG(pInfo));

            gtk_widget_destroy(pInfo);

            g_free(bUtf8);
            g_free(sUtf8);

            gtk_entry_set_text(GTK_ENTRY(entryNouveauPass), (const gchar*) EntreeVide1);
            gtk_entry_set_text(GTK_ENTRY(entryConfirmerPass), (const gchar*) EntreeVide1);

            gtk_switch_set_active(GTK_SWITCH(switchAppLock), (gboolean) FALSE);

            gtk_widget_hide(window8);
            gtk_widget_show(window1);


        }
        else if(Resultat == 1)
        {

            gchar* sUtf8 = 0;
            gchar* bUtf8 = 0;

            bUtf8 = g_locale_from_utf8(" Rien n'as étè changer ", -1, NULL, NULL, NULL);

            sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);


            pInfo = gtk_message_dialog_new (GTK_WINDOW(window8),
                                            GTK_DIALOG_MODAL,
                                            GTK_MESSAGE_INFO,
                                            GTK_BUTTONS_OK,
                                            sUtf8);

            gtk_dialog_run(GTK_DIALOG(pInfo));

            gtk_widget_destroy(pInfo);

            g_free(bUtf8);
            g_free(sUtf8);

        }


    }
    else if ((strcmp(EntreeVide1,Entree1)!=0) && (strcmp(EntreeVide2,Entree2)!=0))
    {

        if(strcmp(Entree1,Entree2)!= 0)
        {

            GtkWidget *pErrorProb;

            gchar* sUtf8 = 0;
            gchar* bUtf8 = 0;

            bUtf8 = g_locale_from_utf8(" Veuillez entrer les mêmes mot de passe dans les deux champs s'il vous plaît ! ", -1, NULL, NULL, NULL);

            sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);


            pErrorProb = gtk_message_dialog_new (GTK_WINDOW(window8),
                                                 GTK_DIALOG_MODAL,
                                                 GTK_MESSAGE_ERROR,
                                                 GTK_BUTTONS_OK,
                                                 sUtf8);

            gtk_dialog_run(GTK_DIALOG(pErrorProb));

            gtk_widget_destroy(pErrorProb);

            g_free(bUtf8);
            g_free(sUtf8);

        }
        else if(strcmp(Entree1,Entree2)== 0)
        {

            char PassSansTiret[MAXCHARS];

            strcpy(PassSansTiret,(const gchar*) Entree1);


            for (int i = 0; PassSansTiret[i]!='\0'; i++)
            {
                if(PassSansTiret[i] == Espace)
                {
                    PassSansTiret[i] = Tiret;
                }
            }

            PassEnabled = 1;
            strcpy(PassFromFile,PassSansTiret);

            SetIDAndPass();

            gchar* sUtf8 = 0;
            gchar* bUtf8 = 0;

            bUtf8 = g_locale_from_utf8(" Mot de passe Enregistré avec succès ", -1, NULL, NULL, NULL);

            sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);


            pInfo = gtk_message_dialog_new (GTK_WINDOW(window8),
                                            GTK_DIALOG_MODAL,
                                            GTK_MESSAGE_INFO,
                                            GTK_BUTTONS_OK,
                                            sUtf8);

            gtk_dialog_run(GTK_DIALOG(pInfo));

            gtk_widget_destroy(pInfo);

            g_free(bUtf8);
            g_free(sUtf8);


            gtk_entry_set_text(GTK_ENTRY(entryNouveauPass), (const gchar*) EntreeVide1);
            gtk_entry_set_text(GTK_ENTRY(entryConfirmerPass), (const gchar*) EntreeVide1);

            gtk_switch_set_active(GTK_SWITCH(switchAppLock), (gboolean) TRUE);


            gtk_widget_hide(window8);
            gtk_widget_show(window1);

        }


    }
    else if (((strcmp(EntreeVide1,Entree1)==0) && (strcmp(EntreeVide2,Entree2)!=0)) || ((strcmp(EntreeVide1,Entree1)!=0) && (strcmp(EntreeVide2,Entree2)==0)))
    {

        GtkWidget *pErrorProb;

        gchar* sUtf8 = 0;
        gchar* bUtf8 = 0;

        bUtf8 = g_locale_from_utf8(" Veuillez rempilir les deux champs s'il vous plaît ! ", -1, NULL, NULL, NULL);

        sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);



        pErrorProb = gtk_message_dialog_new (GTK_WINDOW(window8),
                                             GTK_DIALOG_MODAL,
                                             GTK_MESSAGE_ERROR,
                                             GTK_BUTTONS_OK,
                                             sUtf8);

        gtk_dialog_run(GTK_DIALOG(pErrorProb));

        gtk_widget_destroy(pErrorProb);

        g_free(bUtf8);
        g_free(sUtf8);

    }


}

int MDPvide()
{

    int Reponse = 0;

    GtkWidget *pChangement;


    gchar* sUtf8 = 0;
    gchar* bUtf8 = 0;

    bUtf8 = g_locale_from_utf8(" Attention vous venez de laissez les champs de mot de passe vide !\n ça veut dire que veut venez de désactivez le mot de passe\n êtes-vous sûre de continuer ? ", -1, NULL, NULL, NULL);

    sUtf8 = g_locale_to_utf8(bUtf8, -1, NULL, NULL, NULL);


    pChangement = gtk_message_dialog_new(GTK_WINDOW(window8),
                                         GTK_DIALOG_MODAL,
                                         GTK_MESSAGE_INFO,
                                         GTK_BUTTONS_YES_NO,
                                         sUtf8);

    switch(gtk_dialog_run(GTK_DIALOG(pChangement)))
    {
    case GTK_RESPONSE_YES:
        Reponse = 0;
        gtk_widget_destroy(pChangement);
        break;
    case GTK_RESPONSE_NO:
        Reponse = 1;
        gtk_widget_destroy(pChangement);
        break;
    }

    g_free(bUtf8);
    g_free(sUtf8);

    return Reponse;

}
