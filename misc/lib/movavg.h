float movavg(float z) {
  short c;
  float v = 0;
  for (c = 0; c <= SIZE_WINDOWS - 1; c++) {
    v += x[c];
  }
  return v / SIZE_WINDOWS;
}