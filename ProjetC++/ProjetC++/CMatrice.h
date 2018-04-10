#ifndef CMATRICE_H
#define CMATRICE_H
//#define NULL 0
#include <vector>


using namespace std;


template <typename MType> class CMatrice
{
    //ATTRIBUTS
   private:
        unsigned int uiMATColonne;
        unsigned int uiMATLigne;
        MType type; //PAS NECESSAIRE A MON AVISS
        vector < vector<MType> > Tmatrice;


/************************ CONSTRUCTEURS ET DESTRUCTEUR **********************/
    public:

        CMatrice()
    {
        this->uiMATColonne = 0;
        this->uiMATLigne = 0;
        Tmatrice.resize(0);
    }
                                /*************************************/

        CMatrice ( CMatrice<MType>& MATParam)
        {
            this->uiMATColonne = MATParam.getNMATColonne();
            this->uiMATLigne =MATParam.getNMATLigne();
            this->Tmatrice = MATParam.Tmatrice;

        }

                                /*************************************/

        CMatrice(unsigned int uiLignes, unsigned int uiColonnes)
        {
           unsigned int uiIterateur =0;
            Tmatrice.resize(uiLignes);
            for(uiIterateur=0 ; uiIterateur< Tmatrice.size() ; uiIterateur++){
                Tmatrice[uiIterateur].resize(uiColonnes);
            }

            this->uiMATColonne = uiColonnes;
            this->uiMATLigne = uiLignes;
        }

                                /*************************************/

         //~CMatrice();


      /********************** GETTERS ET SETTERS *************************************/

        unsigned int getNMATColonne()
        {
            return this->uiMATColonne;
        }


                                /*************************************/

        unsigned int getNMATLigne()
        {
            return this->uiMATLigne;
        }

                                /*************************************/


        void setNMATColonne(unsigned int uiColonne)
        {
            this->uiMATColonne = uiColonne;
        }


                                /*************************************/

        void setNMATLigne(unsigned int uiLigne)
        {
             this->uiMATColonne = uiLigne;
        }


/********************** METHODES *************************************/

        MType& operator()(unsigned int uiLigne, unsigned int uiColonne)
        {
           return this->Tmatrice[uiLigne][uiColonne];
        }

                                /*************************************/

        void  MATAffich()

        {   unsigned int uiLigne = 0;
            unsigned int uiColonne = 0;

            for(uiLigne = 0 ; uiLigne < getNMATLigne() ; uiLigne++) {
                for(uiColonne = 0 ; uiColonne < getNMATColonne() ; uiColonne++) {
                    cout << this->Tmatrice[uiLigne][uiColonne] << "\t" ;
                }
           cout << "\n" << endl;
            }
        }


                                /*************************************/




                                /*************************************/

       CMatrice <MType> operator+(CMatrice<MType> &MATParam)
        {
                unsigned int uiColonnes = this ->getNMATColonne();
                 unsigned int uiLignes = this->getNMATLigne();

    //On teste si memes tailles si oui on additionne les (i,j)
                if ( MATParam.getNMATColonne() == uiColonnes && MATParam.getNMATLigne() == uiLignes )
                {
                    unsigned int lignes, colonnes;
                    CMatrice <MType> MATsomme(uiLignes,uiColonnes);

                    for (lignes = 0; lignes < uiLignes ; lignes++){
                        for(colonnes = 0; colonnes < uiColonnes ; colonnes++){
                            MATsomme(lignes,colonnes) = this->Tmatrice[lignes][colonnes]+ MATParam(lignes,colonnes);
                        }
                    }
                    return MATsomme;
                }
                else cout<<"Matrices incompatibles pour addition"<<endl;
        }

                                /*************************************/

         CMatrice <MType> operator=(CMatrice<MType> &MATParam)
         {
             unsigned int uiColonnes = MATParam.getNMATColonne();
             unsigned int uiLignes = MATParam.getNMATLigne() ;

             unsigned int uiLigneCpt;
             unsigned int uiColonneCpt;

             this->setNMATColonne(uiColonnes);
             this->setNMATLigne(uiLignes);

            Tmatrice.resize(uiLignes);
            for(uiLigneCpt=0 ; uiLigneCpt< Tmatrice.size() ; uiLigneCpt++){
                Tmatrice[uiLigneCpt].resize(uiColonnes);
            }

            for (uiLigneCpt= 0; uiLigneCpt < uiLignes ; uiLigneCpt++){
                        for(uiColonneCpt = 0; uiColonneCpt < uiColonnes ; uiColonneCpt++){
                            this->Tmatrice[uiLigneCpt][uiColonneCpt] = MATParam(uiLigneCpt,uiColonneCpt);
                        }
                    }
            return *this;

         }


                                /*************************************/

        CMatrice operator-(CMatrice<MType> &MATParam)
        {
                 unsigned int uiColonnes = this ->getNMATColonne();
                 unsigned int uiLignes = this->getNMATLigne();

                if ( MATParam.getNMATColonne() == uiColonnes && MATParam.getNMATLigne() == uiLignes )
                {
                    int lignes, colonnes;
                    CMatrice <MType> MATsoustraction(uiLignes,uiColonnes);

                    for (lignes = 0; lignes < uiLignes ; lignes++){
                        for(colonnes = 0; colonnes < uiColonnes ; colonnes++){
                            MATsoustraction(lignes,colonnes) = this->Tmatrice[lignes][colonnes]-MATParam(lignes,colonnes);
                        }
                    }
                    return MATsoustraction;
                }
                else cout<<"Matrices incompatibles pour soustraction"<<endl;
        }



                                /*************************************/

        CMatrice<MType> operator*(CMatrice<MType> &MATParam)
        {
             unsigned int uiLigneCpt1;
             unsigned int uiColonneCpt;
             unsigned int uiLigneCpt2;

              CMatrice <MType> MATProduit(this->getNMATLigne(), MATParam.getNMATColonne());

                    unsigned int uiColonnes = MATParam.getNMATColonne();
                    unsigned int uiLignes = MATParam.getNMATLigne();


                if ( MATParam.getNMATLigne() != this->getNMATColonne() )
                {
                    cout<<"Matrices incompatibles pour multiplication"<<endl;
                }
                else
                {

                        unsigned int uiIterateur1,uiIterateur2;
                        for(uiIterateur1=0; uiIterateur1< uiLignes; uiIterateur1++){
                            for(uiIterateur2=0; uiIterateur2 < uiColonnes; uiIterateur2++){
                                    MATProduit(uiIterateur1,uiIterateur2)=0;
                            }
                         }

                    for (uiLigneCpt1 = 0; uiLigneCpt1 < uiLignes ; uiLigneCpt1++){
                        for(uiColonneCpt = 0; uiColonneCpt  < uiColonnes; uiColonneCpt++){
                                 for (uiLigneCpt2 = 0; uiLigneCpt2 < uiLignes; uiLigneCpt2++){
                                    MATProduit(uiLigneCpt1,uiColonneCpt) = (this->Tmatrice[uiLigneCpt1][uiLigneCpt2])*(MATParam(uiLigneCpt2,uiColonneCpt));
                                    //MType result = MATProduit(uiLigneCpt1,uiColonneCpt);
                                 }
                        }
                    }

             }
             return MATProduit;
        }


                                /*************************************/


        CMatrice<MType> operator/(CMatrice<MType> &MATParam)
        {
             unsigned int uiLigneCpt1;
             unsigned int uiColonneCpt;
             unsigned int uiLigneCpt2;

              CMatrice <MType> MATDivision(this->getNMATLigne(), MATParam.getNMATColonne());

                    unsigned int uiColonnes = MATParam.getNMATColonne();
                    unsigned int uiLignes = MATParam.getNMATLigne();


                if ( MATParam.getNMATLigne() != this->getNMATColonne() )
                {
                    cout<<"Matrices incompatibles pour division"<<endl;
                }
                else
                {

                        unsigned int uiIterateur1,uiIterateur2;
                        for(uiIterateur1=0; uiIterateur1< uiLignes; uiIterateur1++){
                            for(uiIterateur2=0; uiIterateur2 < uiColonnes; uiIterateur2++){
                                    MATDivision(uiIterateur1,uiIterateur2)=0;
                            }
                         }

                    for (uiLigneCpt1 = 0; uiLigneCpt1 < uiLignes ; uiLigneCpt1++){
                        for(uiColonneCpt = 0; uiColonneCpt  < uiColonnes; uiColonneCpt++){
                                 for (uiLigneCpt2 = 0; uiLigneCpt2 < uiLignes; uiLigneCpt2++){
                                    MATDivision(uiLigneCpt1,uiColonneCpt) = (this->Tmatrice[uiLigneCpt1][uiLigneCpt2])/(MATParam(uiLigneCpt2,uiColonneCpt));
                                    //MType result = MATProduit(uiLigneCpt1,uiColonneCpt);
                                 }
                        }
                    }

             }
             return MATDivision;
        }


                                /*************************************/




        CMatrice<MType> operator*(MType rConstante)
        {
                    unsigned int uiColonnes = this->getNMATColonne();
                    unsigned int uiLignes = this->getNMATLigne();
                    unsigned int uiLigneCpt;
                    unsigned int uiColonneCpt;

                    CMatrice <MType> MATDivCons(uiLignes,uiColonnes);

                    for( uiLigneCpt=0 ; uiLigneCpt < uiLignes ; uiLigneCpt++){
                        for( uiColonneCpt=0 ; uiColonneCpt < uiColonnes ; uiColonnes ++){
                            MATDivCons(uiLigneCpt,uiColonneCpt) = (this->Tmatrice[uiLigneCpt][uiColonneCpt])*rConstante;
                            MType result = MATDivCons(uiLigneCpt,uiColonneCpt);
                        }
                    }
             return MATDivCons;
        }
        //CMatrice operator/(double rConstante);

        //CMatrice operator*(double rConstante);

        CMatrice& MATLireFichier(char* nomFichier);

        	CMatrice <MType> MATTranspos()
	{
		unsigned int uiColonne = getNMATColonne();
		unsigned int uiLigne = getNMATLigne();
		unsigned int uiColonneCpt;
		unsigned int uiLigneCpt;

		CMatrice <MType> MATTransp(uiColonne, uiLigne);

		for (uiColonneCpt = 0; uiColonneCpt < uiColonne; uiColonneCpt++) {
			for (uiLigneCpt = 0; uiLigneCpt < uiLigne; uiLigneCpt++) {
				MATTransp(uiColonneCpt, uiLigneCpt) = Tmatrice[uiLigneCpt][uiColonneCpt];
			}
		}
		return MATTransp;

	}



};
//#include "CMatrice.cpp"
#endif //CMATRICE_H
