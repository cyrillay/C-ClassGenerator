#include "FenPrincipale.h"
#include "fencodegenere.h"



FenPrincipale::FenPrincipale()
{


    ///LAYOUT PRINCIPAL
    m_layout_principal = new QVBoxLayout;

        ///Objets
            ///formulaire
            m_formulaire = new QGroupBox("Définition de la classe");

                m_champ1 = new QLineEdit("Nom_classe");
                    //m_champ1->connect(m_champ1,SIGNAL(textChanged(QString)),this,SLOT(popup()));
                    m_champ1->setClearButtonEnabled(true);
                m_champ2 = new QLineEdit();

                m_layout_formulaire = new QFormLayout;
                m_layout_formulaire->addRow("Nom : ", m_champ1);
                m_layout_formulaire->addRow("Classe mère : ", m_champ2);

            m_formulaire->setLayout(m_layout_formulaire);

            ///cases à cocher
            m_cases = new QGroupBox("Options");
                m_check1 = new QCheckBox("&Protéger le header contre les inclusions mutliples");
                m_check2 = new QCheckBox("Générer un constructeur par défaut");
                m_check3 = new QCheckBox("Générer un destructeur");

                m_layout_cases = new QVBoxLayout;
                m_layout_cases->addWidget(m_check1);
                m_layout_cases->addWidget(m_check2);
                m_layout_cases->addWidget(m_check3);

            m_cases->setLayout(m_layout_cases);


            ///Ajouter des commentaires
            m_check4 = new QCheckBox("Ajouter des commentaires");



            m_commentaires = new QGroupBox(m_check4);
            m_commentaires->setEnabled(false);
            m_check4->connect(m_check4,SIGNAL(toggled(bool)),m_commentaires,SLOT(setEnabled(bool)));

                m_com1 = new QLineEdit("nom_auteur");
                m_date = new QDateTimeEdit(QDate::currentDate());
                m_texte = new QTextEdit("Vos commentaires ici");

                m_layout_commentaires = new QFormLayout;
                m_layout_commentaires->addRow("&Auteur : ", m_com1);
                m_layout_commentaires->addRow("&Date de création : ",m_date);
                m_layout_commentaires->addRow("&Rôle de la classe : ", m_texte);

            m_commentaires->setLayout(m_layout_commentaires);






            ///boutons de fin
            m_bouton1 = new QPushButton("Générer !",this);
            QString blabla = "essai";
                m_bouton1->connect(m_bouton1,SIGNAL(clicked(bool)),this,SLOT(popup()));

                //m_bouton1->connect(m_bouton1,SIGNAL(clicked(bool)),this,SLOT(popup(&(m_texte->toPlainText()))));
                //m_bouton1->connect(m_bouton1,SIGNAL(clicked(bool)),this,SLOT(close()));
                //this->popup("aazzaazaaaaaaaaaa");
            m_bouton2 = new QPushButton("Quitter",this);
                m_bouton2->connect(m_bouton2,SIGNAL(clicked(bool)),this,SLOT(close()));

    ///ajouts
    m_layout_principal->addWidget(m_formulaire);
    m_layout_principal->addWidget(m_cases);
    m_layout_principal->addWidget(m_check4);
    m_layout_principal->addWidget(m_commentaires);
    m_layout_principal->addWidget(m_bouton1,Qt::AlignRight);
    m_layout_principal->addWidget(m_bouton2,Qt::AlignRight);

    //ajout d'un menu
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
        //ajout d'une action
        QAction *actionQuitter = new QAction("&Quitter", this);
        menuFichier->addAction(actionQuitter);
        actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
        connect(actionQuitter,SIGNAL(triggered(bool)),this,SLOT(close()));

    //ajout d'un 2e menu
    QMenu *menuEdition = menuBar()->addMenu("&Edition");
        //ajout d'un sous-menu
        QMenu* s_menuOptions = menuEdition->addMenu("Options");
            //ajout de 2 actions dans le sous-menu
            QAction* retablir = new QAction("Rétablir");
            s_menuOptions->addAction(retablir);

            QAction* annuler = new QAction("Annuler");
            s_menuOptions->addAction(annuler);


        //ajout d'une action
        QAction* action_test = new QAction("&test");
        menuEdition->addAction(action_test);

    QMenu *menuAffichage = menuBar()->addMenu("&Affichage");

    QWidget* zoneCentrale = new QWidget;
    zoneCentrale->setLayout(m_layout_principal);
    setCentralWidget(zoneCentrale);



    //this->setLayout(m_layout_principal);
}

void FenPrincipale :: popup()
{

    //on vérifie si il y a un nom de classe
    if (m_champ1->text().isEmpty())
    {
        QMessageBox::information(this,"Information","Vous devez renseigner un nom de classe");
        return;
    }
    ///Génération du code

        //commentaires
        m_code="/*\n";
        m_code+="Auteur : " + m_com1->text() + "\n";
        m_code+="Date de création : " + m_date->text() + "\n\n";
        m_code+="Rôle :\n";
        m_code+=m_texte->toPlainText() + "\n";
        m_code+= "*/\n\n";

        //instructions préprocesseur
        if (m_check1->isChecked())
        {
            m_code+="#ifndef HEADER_"+m_champ1->text().toUpper() + "\n";
            m_code+="#define HEADER_"+m_champ1->text().toUpper() + "\n\n\n";
        }

        //Définition de la classe
        m_code+= "class " + m_champ1->text();
        if (QString::compare(m_champ2->text(),"")!=0)
        {
            m_code+= " : public " + m_champ2->text();
        }
        m_code+= "\n{\n";
        m_code+="\tpublic:\n";

        if (m_check2->isChecked())
        {
            m_code+="\t\t" + m_champ1->text() +"();\n";
        }
        if (m_check3->isChecked())
        {
            m_code+="\t\t~" + m_champ1->text() +"();\n";
        }

        m_code+="\n";
        m_code+="\tprotected:\n\n";

        m_code+="\tprivate:\n\n";

        m_code+="};\n\n";

        if (m_check1->isChecked())
        {
            m_code+="#endif HEADER_"+m_champ1->text().toUpper() + "\n";
        }






    ///Génération fenetre
    fencodegenere* nouv = new fencodegenere(&m_code);
    nouv->show();
}

