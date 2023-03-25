#include <iostream>
#include <cstring>
#include <chrono>
#include <ctime>

using namespace std;

// d is the number of characters in the input alphabet
#define d 256

/* pat -> pattern
    txt -> text
    q -> A prime number
*/

//folosim %q pentru a evita numerele f mari (iesim din int);
void search(char pat[], char txt[], int q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++) {

        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters one by one
        if (p == t) {
            /* Check for characters one by one */
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) {
                    break;
                }
            }

            // if p == t and pat[0...M-1] = txt[i, i+1,
            // ...i+M-1]

            if (j == M)
                cout << "Pattern found at index " << i
                << endl;
        }

        // Calculate hash value for next window of text:
        // Remove leading digit, add trailing digit
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;

            // We might get negative value of t, converting
            // it to positive
            if (t < 0)
                t = (t + q);
        }
    }
}

void naive(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j;

        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;

        if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
            cout << "Pattern found at index " << i << endl;
    }
}

/* Driver code */
int main()
{
    clock_t timpinceputn, timpfinaln, timpinceput, timpfinal;
    timpinceput = clock();
    char txt[] = " Erau odat� un mo�neag �i-o bab�; �i mo�neagul avea o fat�, �i baba iar o fat�. Fata babei era slut�, lene��, ��fnoas� �i rea la inim�; dar, pentru c� era fata mamei, se alinta cum s-alint� cioara-n la�, l�s�nd tot greul pe fata mo�neagului. Fata mo�neagului �ns� era frumoas�, harnic�, ascult�toare �i bun� la inim�. Dumnezeu o �mpodobise cu toate darurile cele bune �i frumoase. Dar aceast� fat� bun� era horopsit� �i de sora cea de scoar��, �i de mama cea vitreg�; noroc de la Dumnezeu c� era o fat� robace �i r�bd�toare; c�ci altfel ar fi fost vai �-amar de pielea ei. Fata mo�neagului la deal, fata mo�neagului la vale; ea dup� g�teje prin p�dure, ea cu t�buie�ul �n spate la moar�, ea, �n sf�r�it, �n toate p�r�ile dup� treab�. C�t era ziulica de mare, nu-�i mai str�ngea picioarele; dintr-o parte venea �i-n alta se ducea. �-apoi baba �i cu odorul de fiic�-sa tot c�rtitoare �i nemul�umitoare erau. Pentru bab�, fata mo�neagului era piatr� de moar� �n cas�; iar fata ei, busuioc de pus la icoane.         C�nd se duceau am�ndou� fetele �n sat la �ez�toare seara, fata mo�neagului nu se �ncurca, ci torcea c�te - un ciur plin de fuse; iar fata babei �ndruga �i ea cu mare ce c�te - un fus; � - apoi, c�nd veneau am�ndou� fetele acas� noaptea t�rziu, fata babei s�rea iute peste p�rlaz �i zicea fetei mo�neagului s� - i dea ciurul cu fusele, ca s� - l �ie p�n� va s�ri �i ea.Atunci fata babei, viclean� cum era, lua ciurul �i fuga �n cas� la bab� �i la mo�neag, spun�nd c� ea a tors acele fuse.�n zadar fata mo�neagului spunea �n urm� c� acela este lucrul m�inilor sale; c�ci �ndat� o apucau de obraz baba �i cu fiic� - sa �i trebuia numaidec�t s� r�m�ie pe - a lor.C�nd veneau duminica �i s�rb�torile, fata babei era �mpopo�at� �i netezit� pe cap, de parc - o linseser� vi�eii.Nu era joc, nu era clac� �n sat la care s� nu se duc� fata babei, iar fata mo�neagului era oprit� cu asprime de la toate aceste.� - apoi, c�nd venea mo�neagul de pe unde era dus, gura babei umbla cum umbl� meli�a; c� fata lui nu ascult�, c� - i u�ernic�, c� - i lene��, c� - i soi r�u� c� - i laie, c� - i b�laie; �i c� s - o alunge de la cas�; s - o trimit� la slujb� unde �tie, c� nu - i de chip s - o mai �ie; pentru c� poate s� �nn�r�veasc� �i pe fata ei.  Mo�neagul, fiind un gur�-casc�, sau cum ��i vrea s�-i zice�i, se uita �n coarnele ei, �i ce-i spunea ea sf�nt era. Din inim�, bietul mo�neag poate c-ar fi mai zis c�te ceva; dar acum apucase a c�nta g�ina la casa lui, �i cuco�ul nu mai avea nici o trecere; �-apoi, ia s�-l fi pus p�catul s� se �ntreac� cu dedeochiul; c�ci baba �i cu fiic�-sa �l umplea de bogdaproste.�ntr - una din zile, mo�neagul, fiind foarte am�r�t de c�te - i spunea baba, chem� fata �i - i zise : � Draga tatei, iaca ce - mi tot spune m� - ta de tine : c� n - o ascul�i, c� e�ti rea de gur� �i �nn�r�vit� �i c� nu este de chip s� mai stai la casa mea; de - aceea du - te �i tu �ncotro te - a �ndrepta Dumnezeu, ca s� nu se mai fac� at�ta g�lceav� la casa asta, din pricina ta.Dar te sf�tuiesc, ca un tat� ce - �i sunt, c�, ori�iunde te - i duce, s� fii supus�, blajin� �i harnic�; c�ci la casa mea tot ai dus - o cum ai dus - o: c - a mai fost �i mila p�rinteasc� la mijloc!dar prin str�ini, Dumnezeu �tie peste ce soi de s�m�n�� de oameni �i da; �i nu �i - or putea r�bda c�te �i - am r�bdat noi.";
    char pat[] = "fata";
    // we mod to avoid overflowing of value but we should
    // take as big q as possible to avoid the collison
    int q = 101;

    // Function Call
    search(pat, txt, q);
    timpfinal = clock();
    cout << "Executia programului a durat pentru RK " << (double)(timpfinal - timpinceput) / CLOCKS_PER_SEC << " secunde"<<endl;
    cout << timpinceput << endl;;
    cout << timpfinal << endl;
    timpinceput = clock();
    naive(pat, txt);
    timpfinal = clock();
    cout << "Executia programului a durat pentru naive " << (timpfinal - timpinceput) / CLOCKS_PER_SEC << " secunde";
    return 0;
}
