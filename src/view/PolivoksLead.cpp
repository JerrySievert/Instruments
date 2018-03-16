#include "../controller/PolivoksLead.hpp"

struct PolivoksLeadWidget : ModuleWidget {
  PolivoksLeadWidget(PolivoksLeadModule *module);
};

PolivoksLeadWidget::PolivoksLeadWidget(PolivoksLeadModule *module) : ModuleWidget(module) {
  box.size = Vec(3 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

  {
    SVGPanel *panel = new SVGPanel( );
    panel->box.size = box.size;
    panel->setBackground(SVG::load(assetPlugin(plugin, "res/PolivoksLead.svg")));
    addChild(panel);
  }

  addChild(Widget::create<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
  addChild(Widget::create<ScrewSilver>(
      Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

  addInput(Port::create<PJ301MPort>(Vec(10, 45), Port::INPUT, module,
                                   PolivoksLeadModule::NOTE1_INPUT));
  addOutput(Port::create<PJ301MPort>(Vec(10, 92), Port::OUTPUT, module,
                                     PolivoksLeadModule::AUDIO1_OUTPUT));

}

Model *modelPolivoksLead = Model::create<PolivoksLeadModule, PolivoksLeadWidget>("Instruments", "Polivoks Lead", "Polivoks Lead");
