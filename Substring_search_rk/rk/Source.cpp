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
    char txt[] = " Erau odatã un moºneag ºi-o babã; ºi moºneagul avea o fatã, ºi baba iar o fatã. Fata babei era slutã, leneºã, þâfnoasã ºi rea la inimã; dar, pentru cã era fata mamei, se alinta cum s-alintã cioara-n laþ, lãsând tot greul pe fata moºneagului. Fata moºneagului însã era frumoasã, harnicã, ascultãtoare ºi bunã la inimã. Dumnezeu o împodobise cu toate darurile cele bune ºi frumoase. Dar aceastã fatã bunã era horopsitã ºi de sora cea de scoarþã, ºi de mama cea vitregã; noroc de la Dumnezeu cã era o fatã robace ºi rãbdãtoare; cãci altfel ar fi fost vai º-amar de pielea ei. Fata moºneagului la deal, fata moºneagului la vale; ea dupã gãteje prin pãdure, ea cu tãbuieþul în spate la moarã, ea, în sfârºit, în toate pãrþile dupã treabã. Cât era ziulica de mare, nu-ºi mai strângea picioarele; dintr-o parte venea ºi-n alta se ducea. ª-apoi baba ºi cu odorul de fiicã-sa tot cârtitoare ºi nemulþumitoare erau. Pentru babã, fata moºneagului era piatrã de moarã în casã; iar fata ei, busuioc de pus la icoane.         Când se duceau amândouã fetele în sat la ºezãtoare seara, fata moºneagului nu se încurca, ci torcea câte - un ciur plin de fuse; iar fata babei îndruga ºi ea cu mare ce câte - un fus; º - apoi, când veneau amândouã fetele acasã noaptea târziu, fata babei sãrea iute peste pârlaz ºi zicea fetei moºneagului sã - i dea ciurul cu fusele, ca sã - l þie pânã va sãri ºi ea.Atunci fata babei, vicleanã cum era, lua ciurul ºi fuga în casã la babã ºi la moºneag, spunând cã ea a tors acele fuse.În zadar fata moºneagului spunea în urmã cã acela este lucrul mâinilor sale; cãci îndatã o apucau de obraz baba ºi cu fiicã - sa ºi trebuia numaidecât sã rãmâie pe - a lor.Când veneau duminica ºi sãrbãtorile, fata babei era împopoþatã ºi netezitã pe cap, de parc - o linseserã viþeii.Nu era joc, nu era clacã în sat la care sã nu se ducã fata babei, iar fata moºneagului era opritã cu asprime de la toate aceste.ª - apoi, când venea moºneagul de pe unde era dus, gura babei umbla cum umblã meliþa; cã fata lui nu ascultã, cã - i uºernicã, cã - i leneºã, cã - i soi rãu… cã - i laie, cã - i bãlaie; ºi cã s - o alunge de la casã; s - o trimitã la slujbã unde ºtie, cã nu - i de chip s - o mai þie; pentru cã poate sã înnãrãveascã ºi pe fata ei.  Moºneagul, fiind un gurã-cascã, sau cum îþi vrea sã-i ziceþi, se uita în coarnele ei, ºi ce-i spunea ea sfânt era. Din inimã, bietul moºneag poate c-ar fi mai zis câte ceva; dar acum apucase a cânta gãina la casa lui, ºi cucoºul nu mai avea nici o trecere; º-apoi, ia sã-l fi pus pãcatul sã se întreacã cu dedeochiul; cãci baba ºi cu fiicã-sa îl umplea de bogdaproste.Într - una din zile, moºneagul, fiind foarte amãrât de câte - i spunea baba, chemã fata ºi - i zise : – Draga tatei, iaca ce - mi tot spune mã - ta de tine : cã n - o asculþi, cã eºti rea de gurã ºi înnãrãvitã ºi cã nu este de chip sã mai stai la casa mea; de - aceea du - te ºi tu încotro te - a îndrepta Dumnezeu, ca sã nu se mai facã atâta gâlceavã la casa asta, din pricina ta.Dar te sfãtuiesc, ca un tatã ce - þi sunt, cã, oriºiunde te - i duce, sã fii supusã, blajinã ºi harnicã; cãci la casa mea tot ai dus - o cum ai dus - o: c - a mai fost ºi mila pãrinteascã la mijloc!dar prin strãini, Dumnezeu ºtie peste ce soi de sãmânþã de oameni îi da; ºi nu þi - or putea rãbda câte þi - am rãbdat noi.";
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
