#include "PolivoksSaw.hpp"
#include "../samples/saw.h"

static struct PolivoksSawContainer sawsamples[ 36 ] = {
  { (float *) sawc3,  sawc3_len,  0 },
  { (float *) sawcs3, sawcs3_len, 1 },
  { (float *) sawd3,  sawd3_len,  2 },
  { (float *) sawds3, sawds3_len, 3 },
  { (float *) sawe3,  sawe3_len,  4 },
  { (float *) sawf3,  sawf3_len,  5 },
  { (float *) sawfs3, sawfs3_len, 6 },
  { (float *) sawg3,  sawg3_len,  7 },
  { (float *) sawgs3, sawgs3_len, 8 },
  { (float *) sawa3,  sawa3_len,  9 },
  { (float *) sawas3, sawas3_len, 10 },
  { (float *) sawb3,  sawb3_len,  11 },
  { (float *) sawc4,  sawc4_len,  12 },
  { (float *) sawcs4, sawcs4_len, 13 },
  { (float *) sawd4,  sawd4_len,  14 },
  { (float *) sawds4, sawds4_len, 15 },
  { (float *) sawe4,  sawe4_len,  16 },
  { (float *) sawf4,  sawf4_len,  17 },
  { (float *) sawfs4, sawfs4_len, 18 },
  { (float *) sawg4,  sawg4_len,  19 },
  { (float *) sawgs4, sawgs4_len, 20 },
  { (float *) sawa4,  sawa4_len,  21 },
  { (float *) sawas4, sawas4_len, 22 },
  { (float *) sawb4,  sawb4_len,  23 },
  { (float *) sawc5,  sawc5_len,  24 },
  { (float *) sawcs5, sawcs5_len, 25 },
  { (float *) sawd5,  sawd5_len,  26 },
  { (float *) sawds5, sawds5_len, 27 },
  { (float *) sawe5,  sawe5_len,  28 },
  { (float *) sawf5,  sawf5_len,  29 },
  { (float *) sawfs5, sawfs5_len, 30 },
  { (float *) sawg5,  sawg5_len,  31 },
  { (float *) sawgs5, sawgs5_len, 32 },
  { (float *) sawa5,  sawa5_len,  33 },
  { (float *) sawas5, sawas5_len, 34 },
  { (float *) sawb5,  sawb5_len,  35 }
};

static float sawnotes[36] = {
  -2, -1.92, -1.83, -1.75, -1.67, -1.58, -1.5, -1.42, -1.33, -1.25, -1.17, -1.08,
  -1, -0.92, -0.83, -0.75, -0.67, -0.58, -0.5, -0.42, -0.33, -0.25, -0.17, -0.08,
  0, 0.08, 0.17, 0.25, 0.33, 0.42, 0.5, 0.58, 0.67, 0.75, 0.83, 0.92
};

static struct PolivoksSawContainer *sawGetNote(float current) {
  for (int i = 0; i < 36; i++) {
    if ((sawnotes[i] - 0.02) <= current && (sawnotes[i] + 0.02) >= current) {
      return &sawsamples[i];
    }
  }

  return NULL;
}

PolivoksSawModule::PolivoksSawModule( ) : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS) {
  currentStep = 0;
  last = -1;
}

void PolivoksSawModule::step( ) {
  float in1 = inputs[ NOTE1_INPUT ].value;
  struct PolivoksSawContainer *note;

  // check the first note
  note = sawGetNote(in1);

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
