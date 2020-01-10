#include <iostream>
#include <vector>
using namespace std;

class Candidat {
protected:
    string nume;
    float media_bacalaureat;
public:
    Candidat () {
    nume = '\0';
    media_bacalaureat = 0;
    }
    ~Candidat () {};
    friend istream& operator >> ( istream &, Candidat & );
    friend ostream& operator << ( ostream &, Candidat & );
    friend class Candidat_ID;
    friend class Candidat_ID2;
    friend class Candidat_IF;
    friend class Candidat_IF2;
};

istream& operator >> ( istream &in , Candidat &a ) {
    cout << " introduceti numele candidatului: ";
    in >> a.nume;
    cout << " introduceti media de la bacalaureat: ";
    in >> a.media_bacalaureat;
    //cout << " introduceti "
    return in;
}

ostream& operator << ( ostream& out, Candidat &a ) {
    out << "numele candidatului: " << a.nume << endl;
    out << "media de la bacalaureat: " << a.media_bacalaureat << endl;
    return out;
}

class Candidat_ID : public Candidat {
    float nota_matematica, nota_oral, nota_admitere;
    int id_id;
public:
    Candidat_ID () : Candidat () {
    nota_matematica = 0;
    nota_oral = 0;
    id_id = 0;
    nota_admitere = 0;
    }
    Candidat_ID ( int a ) : Candidat () {
    id_id = a;
    nota_oral = 0;
    nota_matematica = 0;
    nota_admitere = 0;
    }
    ~Candidat_ID () {};
    friend istream& operator >> ( istream& , Candidat_ID & );
    friend ostream& operator << ( ostream& , Candidat_ID & );
    friend class Candidat;
};

istream& operator >> ( istream& in , Candidat_ID & a) {
    cout << "introduceti nota la matematica: ";
    in >> a.nota_matematica;
    cout << "introduceti nota la oral: ";
    in >> a.nota_oral;
    in >> ( Candidat & ) a;
    a.nota_admitere = 0.6 * a.nota_oral + 0.4 * a.nota_matematica;
    return in;
}

ostream& operator << ( ostream& out , Candidat_ID & a ) {
    out << "nota la matematica: " << a.nota_matematica << endl;
    out << "nota la oral: " << a.nota_oral << endl;
    out << "nota admitere: " << a.nota_admitere;
    out << "id-ul: ID_" << a.id_id << endl;
    out << ( Candidat & ) a;
}

class Candidat_IF : public Candidat {
    float nota_admitere, nota_subiect1, nota_subiect2;
    int id_if;
public:
    Candidat_IF () : Candidat () {
    nota_admitere = 0;
    nota_subiect1 = 0;
    nota_subiect2 = 0;
    id_if = 0;
    }
    Candidat_IF ( int a ) : Candidat () {
    nota_admitere = 0;
    nota_subiect1 = 0;
    nota_subiect2 = 0;
    id_if = a;
    }
    friend istream& operator >> ( istream & , Candidat_IF & );
    friend ostream& operator << ( ostream & , Candidat_IF & );
    friend class Candidat;
};

istream& operator >> ( istream &in , Candidat_IF &a ){
    cout << "nota subiect 1: ";
    in >> a.nota_subiect1;
    cout << "nota subiect 2: ";
    in >> a.nota_subiect2;
    in >> ( Candidat & ) a;
    float nota_concurs = ( a.nota_subiect1 + a.nota_subiect2 )/2;
    a.nota_admitere = 0.8 * nota_concurs + 0.2 * a.media_bacalaureat;
};

ostream& operator << ( ostream &out , Candidat_IF &a ) {
    out << "nota subiect 1: " << a.nota_subiect1 << endl;
    out << "nota subiect 2: " << a.nota_subiect2 << endl;
    out << "nota admitere : " << a.nota_admitere << endl;
    out << "id-ul: " << a.id_if << endl;
    out << ( Candidat & ) a;
    return out;
}

class Candidat_ID2 : public Candidat {
    float media_facultate, nota_oral, nota_admitere;
    int id_id2;
public:
    Candidat_ID2 ( int a ) : Candidat () {
    //program = 0;
    media_facultate = 0;
    nota_oral = 0;
    nota_admitere = 0;
    id_id2 = a;
    }
    ~Candidat_ID2 () {};
    friend istream& operator >> ( istream & , Candidat_ID2 & );
    friend ostream& operator << ( ostream & , Candidat_ID2 & );
    friend class Candidat;
};

istream& operator >> ( istream &in , Candidat_ID2 & a ) {
    cout << "introduceti media de la facultate: ";
    in >> a.media_facultate;
    cout << "introduceti nota de la oral: ";
    in >> a.nota_oral;
    in >> ( Candidat & ) a;
    a.nota_admitere = 0.6 * a.nota_oral + 0.4 * a.media_facultate;
    return in;
}

ostream& operator << ( ostream &out, Candidat_ID2 & a ) {
    out << "nota la prima facultate: " << a.media_facultate << endl;
    out << "nota oral: " << a.nota_oral << endl;
    out << "nota admitere: " << a.nota_admitere << endl;
    out << "id: ID2_" << a.id_id2 << endl;
    out << ( Candidat& ) a;
    return out;
}

class Candidat_IF2 : public Candidat {
    float nota_oral, media_facultate,nota_admitere;
    int id_if2;
public:
    Candidat_IF2 ( int a ) : Candidat () {
    nota_oral = 0;
    media_facultate = 0;
    nota_admitere = 0;
    id_if2 = 0;
    }
    ~Candidat_IF2 () {};
    friend istream& operator >> ( istream& , Candidat_IF2 & );
    friend ostream& operator << ( ostream& , Candidat_IF2 & );
    friend class Candidat;
};

istream& operator >> ( istream & in , Candidat_IF2 &a ) {
    cout << "introduceti media de la facultate: ";
    in >> a.media_facultate;
    cout << "introduceti media de la oral: ";
    in >> a.nota_oral;
    a.nota_admitere = 0.6 * a.nota_oral + 0.4 * a.media_facultate;
    in >> ( Candidat& ) a;
    return in;
}

template < class Admitere > class Facultate;
template < class Admitere > istream& operator >> ( istream & , Facultate < Admitere > & );
template < class Admitere > ostream& operator << ( ostream & , Facultate < Admitere > & );

template < class Admitere >
class Facultate {
    int id;
    int locuri_id,locuri_if;
    int procent_locuri_taxa_id, procent_locuri_taxa_if;
    vector < Candidat_ID > Cand_ID;
    vector < Candidat_IF > Cand_IF;
    vector < Candidat_ID2 > Cand_ID2;
    vector < Candidat_IF2 > Cand_IF2;
public:
    Facultate ( int a , int b , int c , int d ) : locuri_id ( a ) , locuri_if ( b ) , procent_locuri_taxa_id ( c ) , procent_locuri_taxa_if ( d ) { id = 1; }
    ~Facultate ();
    friend istream& operator >> ( istream& , Facultate < Admitere > & );
    friend ostream& operator << ( ostream& , Facultate < Admitere > & );
    void locuri_procente ( int a , int b , int c , int d ){
        locuri_id = a;
        locuri_if = b;
        procent_locuri_taxa_id = c;
        procent_locuri_taxa_if = d;
    }
};

template < class Admitere >
istream& operator >> ( istream &in , Facultate < Admitere > &a ){
    int x;
    cout << "1. ID " << endl;
    cout << "2. IF " << endl;
    cout << "3. ID2 " << endl;
    cout << "4. IF2 " << endl;
    cout << "introduceti tipul de candidat: ";
    cin >> x;
    switch ( x ) {
        case 1:
            a.id ++;
            Candidat_ID temp_id ( a.id );
            in >> temp_id;
            a.Cand_ID.push_back( temp_id );
            break;
        case 2:
            a.id ++;
            Candidat_IF temp_if ( a.id );
            in >> temp_if;
            a.Cand_IF.push_back( temp_if );
            break;
        case 3:
            a.id ++;
            Candidat_ID2 temp_id2 ( a.id );
            in >> temp_id2;
            a.Cand_ID2.push_back ( temp_id2 );
        case 4:
            a.id ++;
            Candidat_IF2 temp_if2 ( a.id );
            in >> temp_if2;
            a.Cand_IF2.push_back ( temp_if2 );
    }
    return in;
 }



int main()
{
    cout << "introduceti numarul de locuri si % locurilor cu taxa ( ID ) ";
    int locuri_id, procent_id, locuri_if, procent_if;
        cin >> locuri_id >> procent_id;
    cout << "introduceti numarul de locuri si % locurilor cu taxa ( IF ) ";
        cin >> locuri_if >> procent_if;
    //Facultate < Admitere > fac :: locuri_procente ( locuri_id , locuri_if , procent_id , procent_if );
    int x;
    while ( 1 ) {
        cout << "1. Adaugati un nou candidat" << endl;
        cout << "2. Afisati numarul si listele cu toti candidatii inscrisi la fiecare program" << endl;
        cout << "3. Afisati listele cu cei declarati admisi la fiecare program" << endl;
        cout << "4. Afisati numarul si datele candidatilor admisi care s-au inscris pe baza pasaportului" << endl;
        cout << "5. Exit" << endl;
        cout << "Introduceti o optiune: " << endl;
        cin >> x;
        switch ( x ) {
            case 1: {}
            case 5: {
            return 0;
            break;
            }
        }
    }
    return 0;
}
