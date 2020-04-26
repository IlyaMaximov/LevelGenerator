#ifndef LEVELGENERATOR_MOUSESTATUS_H
#define LEVELGENERATOR_MOUSESTATUS_H

#include "../GeomObjects/Button.h"

struct MouseStatus {

    static TextureName getLandscape() {
        assert(landscape != nullptr);
        return landscape->getTextureName();
    }

    static LandscapeButton* getLandscapeButton() {
        return landscape;
    }

    static void setLandscapeButton(LandscapeButton* button) {
        assert(landscape != button);
        if (button!= nullptr && landscape != nullptr) {
            landscape->click();
        }
        assert(button == nullptr || landscape == nullptr);
        landscape = button;
    }

private:
    static LandscapeButton* landscape;
};


#endif //LEVELGENERATOR_MOUSESTATUS_H
