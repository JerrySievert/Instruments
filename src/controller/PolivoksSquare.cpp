#include "PolivoksSquare.hpp"
#include "../samples/square.h"

static struct PolivoksSquareContainer Squaresamples[ 24 ] = {
  { (float *) squarec1,  squarec1_len,  0 },
  { (float *) squarecs1, squarecs1_len, 1 },
  { (float *) squared1,  squared1_len,  2 },
  { (float *) squareds1, squareds1_len, 3 },
  { (float *) squaree1,  squaree1_len,  4 },
  { (float *) squaref1,  squaref1_len,  5 },
  { (float *) squarefs1, squarefs1_len, 6 },
  { (float *) squareg1,  squareg1_len,  7 },
  { (float *) squaregs1, squaregs1_len, 8 },
  { (float *) squarea1,  squarea1_len,  9 },
  { (float *) squareas1, squareas1_len, 10 },
  { (float *) squareb1,  squareb1_len,  11 },
  { (float *) squarec2,  squarec2_len,  12 },
  { (float *) squarecs2, squarecs2_len, 13 },
  { (float *) squared2,  squared2_len,  14 },
  { (float *) squareds2, squareds2_len, 15 },
  { (float *) squaree2,  squaree2_len,  16 },
  { (float *) squaref2,  squaref2_len,  17 },
  { (float *) squarefs2, squarefs2_len, 18 },
  { (float *) squareg2,  squareg2_len,  19 },
  { (float *) squaregs2, squaregs2_len, 20 },
  { (float *) squarea2,  squarea2_len,  21 },
  { (float *) squareas2, squareas2_len, 22 },
  { (float *) squareb2,  squareb2_len,  23 }
};

static float Squarenotes[24] = {
  -2, -1.92, -1.83, -1.75, -1.67, -1.58, -1.5, -1.42, -1.33, -1.25, -1.17, -1.08,
  -1, -0.92, -0.83, -0.75, -0.67, -0.58, -0.5, -0.42, -0.33, -0.25, -0.17, -0.08
};

static struct PolivoksSquareContainer *SquareGetNote(float current) {
  for (int i = 0; i < 24; i++) {
    if ((Squarenotes[i] - 0.02) <= current && (Squarenotes[i] + 0.02) >= current) {
      return &Squaresamples[i];
    }
  }

  return NULL;
}

PolivoksSquareModule::PolivoksSquareModule( ) : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS) {
  currentStep = 0;
  last = -1;
}

void PolivoksSquareModule::step( ) {
  float in1 = inputs[ NOTE1_INPUT ].value;
  struct PolivoksSquareContainer *note;

  // check the first note
  note = SquareGetNote(in1);

  if (note == NULL) {
    currentStep = 0;
    outputs[ AUDIO1_OUTPUT ].value = 0;
    last = -1;
  } else {
    if (last != note->current) {
      last = note->current;
      currentStep = 0;
    }

    if (currentStep == note->length) {
      currentStep = 0;
    }

    outputs[ AUDIO1_OUTPUT ].value = note->sample[currentStep];
    currentStep++;
  }
}
