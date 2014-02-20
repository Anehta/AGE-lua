
#-------------------------------------------------
#
# Project created by QtCreator 2014-01-19T23:22:01
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += xml multimedia

TARGET = AGE2DGame
TEMPLATE = app

SOURCES += \
    game.cpp \
    main.cpp \
    ../src/shader/age_shader.cpp \
    ../src/shader/age_shaderprogram.cpp \
    ../src/render/age_accumulator.cpp \
    ../src/render/age_animation.cpp \
    ../src/render/age_animationset.cpp \
    ../src/render/age_cramera.cpp \
    ../src/render/age_frame.cpp \
    ../src/render/age_framelistener.cpp \
    ../src/render/age_geometric.cpp \
    ../src/render/age_node.cpp \
    ../src/render/age_sprite.cpp \
    ../src/render/age_spriteactor.cpp \
    ../src/render/age_texture.cpp \
    ../src/math/age_matrix4x4.cpp \
    ../src/math/age_point.cpp \
    ../src/math/age_pointf.cpp \
    ../src/math/age_polygon.cpp \
    ../src/math/age_vector2d.cpp \
    ../src/math/age_vector3d.cpp \
    ../src/math/age_vector4d.cpp \
    ../src/listener/age_baselistener.cpp \
    ../src/listener/age_eventlistener.cpp \
    ../src/listener/age_eventmgr.cpp \
    ../src/listener/age_keyboardevent.cpp \
    ../src/listener/age_keylistener.cpp \
    ../src/listener/age_mouselistener.cpp \
    ../src/info/age_mouseinfo.cpp \
    ../src/framework/age_application.cpp \
    ../src/framework/age_layer.cpp \
    ../src/framework/age_scene.cpp \
    ../src/framework/age_utility.cpp \
    ../src/framework/age_widget.cpp \
    ../src/framework/age_widgetevent.cpp \
    ../src/framework/age_system.cpp \
    ../src/framework/age_staticattribute.cpp \
    ../src/audio/age_audio.cpp \
    ../src/font/age_font.cpp \
    ../src/framework/age_baseentity.cpp \
    menu/menuscene.cpp \
    ../src/math/age_regexp.cpp \
    particle.cpp \
    particlelauncher.cpp \
    hero/hero.cpp \
    back_ground.cpp \
    bullet.cpp \
    ../src/Box2D/Collision/Shapes/b2ChainShape.cpp \
    ../src/Box2D/Collision/Shapes/b2CircleShape.cpp \
    ../src/Box2D/Collision/Shapes/b2EdgeShape.cpp \
    ../src/Box2D/Collision/Shapes/b2PolygonShape.cpp \
    ../src/Box2D/Collision/b2BroadPhase.cpp \
    ../src/Box2D/Collision/b2CollideCircle.cpp \
    ../src/Box2D/Collision/b2CollideEdge.cpp \
    ../src/Box2D/Collision/b2CollidePolygon.cpp \
    ../src/Box2D/Collision/b2Collision.cpp \
    ../src/Box2D/Collision/b2Distance.cpp \
    ../src/Box2D/Collision/b2DynamicTree.cpp \
    ../src/Box2D/Collision/b2TimeOfImpact.cpp \
    ../src/Box2D/Common/b2BlockAllocator.cpp \
    ../src/Box2D/Common/b2Draw.cpp \
    ../src/Box2D/Common/b2Math.cpp \
    ../src/Box2D/Common/b2Settings.cpp \
    ../src/Box2D/Common/b2StackAllocator.cpp \
    ../src/Box2D/Common/b2Timer.cpp \
    ../src/Box2D/Dynamics/b2Body.cpp \
    ../src/Box2D/Dynamics/b2ContactManager.cpp \
    ../src/Box2D/Dynamics/b2Fixture.cpp \
    ../src/Box2D/Dynamics/b2Island.cpp \
    ../src/Box2D/Dynamics/b2World.cpp \
    ../src/Box2D/Dynamics/b2WorldCallbacks.cpp \
    ../src/Box2D/Dynamics/Contacts/b2ChainAndCircleContact.cpp \
    ../src/Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.cpp \
    ../src/Box2D/Dynamics/Contacts/b2CircleContact.cpp \
    ../src/Box2D/Dynamics/Contacts/b2Contact.cpp \
    ../src/Box2D/Dynamics/Contacts/b2ContactSolver.cpp \
    ../src/Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.cpp \
    ../src/Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.cpp \
    ../src/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.cpp \
    ../src/Box2D/Dynamics/Contacts/b2PolygonContact.cpp \
    ../src/Box2D/Dynamics/Joints/b2DistanceJoint.cpp \
    ../src/Box2D/Dynamics/Joints/b2FrictionJoint.cpp \
    ../src/Box2D/Dynamics/Joints/b2GearJoint.cpp \
    ../src/Box2D/Dynamics/Joints/b2Joint.cpp \
    ../src/Box2D/Dynamics/Joints/b2MotorJoint.cpp \
    ../src/Box2D/Dynamics/Joints/b2MouseJoint.cpp \
    ../src/Box2D/Dynamics/Joints/b2PrismaticJoint.cpp \
    ../src/Box2D/Dynamics/Joints/b2PulleyJoint.cpp \
    ../src/Box2D/Dynamics/Joints/b2RevoluteJoint.cpp \
    ../src/Box2D/Dynamics/Joints/b2RopeJoint.cpp \
    ../src/Box2D/Dynamics/Joints/b2WeldJoint.cpp \
    ../src/Box2D/Dynamics/Joints/b2WheelJoint.cpp \
    ../src/Box2D/Rope/b2Rope.cpp \
    AI/ai.cpp \
    ../lua_src/lapi.c \
    ../lua_src/lauxlib.c \
    ../lua_src/lbaselib.c \
    ../lua_src/lbitlib.c \
    ../lua_src/lcode.c \
    ../lua_src/lcorolib.c \
    ../lua_src/lctype.c \
    ../lua_src/ldblib.c \
    ../lua_src/ldebug.c \
    ../lua_src/ldo.c \
    ../lua_src/ldump.c \
    ../lua_src/lfunc.c \
    ../lua_src/lgc.c \
    ../lua_src/linit.c \
    ../lua_src/liolib.c \
    ../lua_src/llex.c \
    ../lua_src/lmathlib.c \
    ../lua_src/lmem.c \
    ../lua_src/loadlib.c \
    ../lua_src/lobject.c \
    ../lua_src/lopcodes.c \
    ../lua_src/loslib.c \
    ../lua_src/lparser.c \
    ../lua_src/lstate.c \
    ../lua_src/lstring.c \
    ../lua_src/lstrlib.c \
    ../lua_src/ltable.c \
    ../lua_src/ltablib.c \
    ../lua_src/ltm.c \
    ../lua_src/lua.c \
    ../lua_src/luac.c \
    ../lua_src/lundump.c \
    ../lua_src/lvm.c \
    ../lua_src/lzio.c \
    age_interface.cpp \
    age_lua.cpp \
    ../src/framework/age_luawidget.cpp

HEADERS  += \
    ../include/age_accumulator.h \
    ../include/age_animation.h \
    ../include/age_animationset.h \
    ../include/age_application.h \
    ../include/age_baselistener.h \
    ../include/age_cramera.h \
    ../include/age_eventlistener.h \
    ../include/age_eventmgr.h \
    ../include/age_eventsource.h \
    ../include/age_frame.h \
    ../include/age_framelistener.h \
    ../include/age_geometric.h \
    ../include/age_keyboardevent.h \
    ../include/age_keylistener.h \
    ../include/age_layer.h \
    ../include/age_matrix4x4.h \
    ../include/age_mouseinfo.h \
    ../include/age_mouselistener.h \
    ../include/age_node.h \
    ../include/age_point.h \
    ../include/age_pointf.h \
    ../include/age_polygon.h \
    ../include/age_scene.h \
    ../include/age_shader.h \
    ../include/age_shaderprogram.h \
    ../include/age_sprite.h \
    ../include/age_spriteactor.h \
    ../include/age_system.h \
    ../include/age_texture.h \
    ../include/age_utility.h \
    ../include/age_vector2d.h \
    ../include/age_vector3d.h \
    ../include/age_vector4d.h \
    ../include/age_widget.h \
    ../include/background.h \
    ../include/bullet.h \
    ../include/game.h \
    ../include/hero.h \
    ../include/herolistener.h \
    ../include/mylayer.h \
    ../include/mylayerlistener.h \
    game.h \
    ../include/AGE2D.h \
    ../include/age_audio.h \
    ../include/age_staticattribute.h \
    ../include/age_font.h \
    ../include/age_baseentity.h \
    ../include/age_color.h \
    menu/menuscene.h \
    ../include/age_regexp.h \
    particle.h \
    particlelauncher.h \
    hero/hero.h \
    back_ground.h \
    bullet.h \
    ../library/Box2D/Box2D.h \
    AI/ai.h \
    ../lua_src/lapi.h \
    ../lua_src/lauxlib.h \
    ../lua_src/lcode.h \
    ../lua_src/lctype.h \
    ../lua_src/ldebug.h \
    ../lua_src/ldo.h \
    ../lua_src/lfunc.h \
    ../lua_src/lgc.h \
    ../lua_src/llex.h \
    ../lua_src/llimits.h \
    ../lua_src/lmem.h \
    ../lua_src/lobject.h \
    ../lua_src/lopcodes.h \
    ../lua_src/lparser.h \
    ../lua_src/lstate.h \
    ../lua_src/lstring.h \
    ../lua_src/ltable.h \
    ../lua_src/ltm.h \
    ../lua_src/lua.h \
    ../lua_src/lua.hpp \
    ../lua_src/luaconf.h \
    ../lua_src/lualib.h \
    ../lua_src/lundump.h \
    ../lua_src/lvm.h \
    ../lua_src/lzio.h \
    age_interface.h \
    age_lua.h \
    ../include/age_luawidget.h

CONFIG += mobility c++11
MOBILITY =

OTHER_FILES += \
    android/AndroidManifest.xml

RESOURCES +=

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../src/freetype/ -lfreetype
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../src/freetype/ -lfreetyped
else:unix: LIBS += -L$$PWD/../src/freetype/ -lfreetype

INCLUDEPATH += $$PWD/../src/freetype
DEPENDPATH += $$PWD/../src/freetype

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../src/freetype/libfreetype.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../src/freetype/libfreetyped.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../src/freetype/freetype.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../src/freetype/freetyped.lib
else:unix: PRE_TARGETDEPS += $$PWD/../src/freetype/libfreetype.a

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
