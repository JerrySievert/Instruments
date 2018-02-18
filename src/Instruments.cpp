#include "Instruments.hpp"

// The plugin-wide instance of the Plugin class
Plugin *plugin;

void init(rack::Plugin *p) {
  plugin = p;
  // This is the unique identifier for your plugin
  p->slug = "Instruments";
#ifdef VERSION
  p->version = TOSTRING(VERSION);
#endif
  p->website = "https://github.com/JerrySievert/Instruments";
  p->manual  = "https://github.com/JerrySievert/Instruments/blob/master/README.md";

  p->addModel(createModel<PolivoksLeadWidget>("Instruments", "Polivoks Lead", "Polivoks Lead"));
  p->addModel(createModel<PolivoksSawWidget>("Instruments", "Polivoks Saw", "Polivoks Saw"));

}
