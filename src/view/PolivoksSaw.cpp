#include "../controller/PolivoksSaw.hpp"

struct PolivoksSawWidget : ModuleWidget {
  PolivoksSawWidget(PolivoksSawModule *module);
};

PolivoksSawWidget::PolivoksSawWidget(PolivoksSawModule *module) : ModuleWidget(module) {
  box.size = Vec(3 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

  {
    SVGPanel *panel = new SVGPanel( );
    panel->box.size = box.size;
    panel->setBackground(SVG::load(assetPlugin(plugin, "res/PolivoksSaw.svg")));
    addChild(panel);
  }

  addChild(Widget::create<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
  addChild(Widget::create<ScrewSilver>(
      Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

  addInput(Port::create<PJ301MPort>(Vec(10, 45), Port::INPUT, module,
                                   PolivoksSawModule::NOTE1_INPUT));
  addOutput(Port::create<PJ301MPort>(Vec(10, 92), Port::OUTPUT, module,
                                     PolivoksSawModule::AUDIO1_OUTPUT));

}

Model *modelPolivoksSaw = Model::create<PolivoksSawModule, PolivoksSawWidget>("Instruments", "Polivoks Saw", "Polivoks Saw");
