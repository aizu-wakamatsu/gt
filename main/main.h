#define PIN_ANLG A0
#define PIN_LED A1
#define PIN_SW A2
#define FILENAME "data.csv"

const short RATE_SAMPLE = 200;
const short SIZE_WINDOWS = 11;

const short SECS_MEASURES = 20;

float coef[SIZE_WINDOWS];
/* 
void param_coef() {// f=0.25
  coef[0] = 6.366197723675814e-02;
  coef[1] = -1.949085916259688e-17;
  coef[2] = -1.061032953945969e-01;
  coef[3] = 1.949085916259688e-17;
  coef[4] = 3.183098861837907e-01;
  coef[5] = 5.000000000000000e-01;
  coef[6] = 3.183098861837907e-01;
  coef[7] = 1.949085916259688e-17;
  coef[8] = -1.061032953945969e-01;
  coef[9] = -1.949085916259688e-17;
  coef[10] = 6.366197723675814e-02;
}
*/
void param_coef() {  // f=0.2
  coef[0] = -1.559268733007750e-17;
  coef[1] = -7.568267286406570e-02;
  coef[2] = -6.236595225257593e-02;
  coef[3] = 9.354892837886393e-02;
  coef[4] = 3.027306914562628e-01;
  coef[5] = 4.000000000000000e-01;
  coef[6] = 3.027306914562628e-01;
  coef[7] = 9.354892837886393e-02;
  coef[8] = -6.236595225257593e-02;
  coef[9] = -7.568267286406570e-02;
  coef[10] = -1.559268733007750e-17;
}