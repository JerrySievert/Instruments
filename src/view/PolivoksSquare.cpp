#include "../controller/PolivoksSquare.hpp"

struct PolivoksSquareWidget : ModuleWidget {
  PolivoksSquareWidget(PolivoksSquareModule *module);
};

PolivoksSquareWidget::PolivoksSquareWidget(PolivoksSquareModule *module) : ModuleWidget(module) {
  box.size = Vec(3 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);

  {
    SVGPanel *panel = new SVGPanel( );
    panel->box.size = box.size;
    panel->setBackground(SVG::load(assetPlugin(plugin, "res/PolivoksSquare.svg")));
    addChild(panel);
  }

  addChild(Widget::create<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
  addChild(Widget::create<ScrewSilver>(
      Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

  addInput(Port::create<PJ301MPort>(Vec(10, 45), Port::INPUT, module,
                                   PolivoksSquareModule::NOTE1_INPUT));
  addOutput(Port::create<PJ301MPort>(Vec(10, 92), Port::OUTPUT, module,
                                     PolivoksSquareModule::AUDIO1_OUTPUT));

}

Model *modelPolivoksSquare = Model::create<PolivoksSquareModule, PolivoksSquareWidget>("Instruments", "Polivoks Square", "Polivoks Square");
