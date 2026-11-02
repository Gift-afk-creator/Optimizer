
#include <Geode/Geode.hpp>
#include <Geode/modify/CCParticleSystemQuad.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

static bool opt(char const* key) {
    return Mod::get()->getSettingValue<bool>(key);
}

// Partículas: solo se omiten dentro de un nivel (los menús no se tocan)
class $modify(LiteParticles, CCParticleSystemQuad) {
    void draw() override {
        if (opt("no-particles") && PlayLayer::get()) return;
        CCParticleSystemQuad::draw();
    }
};

// Temblor de cámara
class $modify(LiteShake, GJBaseGameLayer) {
    void shakeCamera(float duration, float strength, float interval) {
        if (opt("no-shake")) return;
        GJBaseGameLayer::shakeCamera(duration, strength, interval);
    }
};

// Efecto de muerte
class $modify(LiteDeath, PlayerObject) {
    void playDeathEffect() {
        if (opt("no-death-effects")) return;
        PlayerObject::playDeathEffect();
    }
};
