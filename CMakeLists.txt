cmake_minimum_required(VERSION 3.0...3.10)
project(li-po
   VERSION 0.1.0
   LANGUAGES C CXX
)
set (CMAKE_CXX_STANDARD 98)

add_subdirectory(Source/CommonLibs/NonDF/SDL2 EXCLUDE_FROM_ALL)
add_subdirectory(Source/CommonLibs/NonDF/mojoshader EXCLUDE_FROM_ALL)
add_subdirectory(Source/CommonLibs/NonDF/mojoAL EXCLUDE_FROM_ALL)

# Lua 
add_library(liblua STATIC
   Source/CommonLibs/NonDF/lua-4.0.1/src/lapi.c 
   Source/CommonLibs/NonDF/lua-4.0.1/src/lcode.c 
   Source/CommonLibs/NonDF/lua-4.0.1/src/ldebug.c 
   Source/CommonLibs/NonDF/lua-4.0.1/src/ldo.c 
   Source/CommonLibs/NonDF/lua-4.0.1/src/lfunc.c 
   Source/CommonLibs/NonDF/lua-4.0.1/src/lgc.c 
   Source/CommonLibs/NonDF/lua-4.0.1/src/llex.c 
   Source/CommonLibs/NonDF/lua-4.0.1/src/lmem.c
   Source/CommonLibs/NonDF/lua-4.0.1/src/lobject.c 
   Source/CommonLibs/NonDF/lua-4.0.1/src/lparser.c 
   Source/CommonLibs/NonDF/lua-4.0.1/src/lstate.c 
   Source/CommonLibs/NonDF/lua-4.0.1/src/lstring.c 
   Source/CommonLibs/NonDF/lua-4.0.1/src/ltable.c 
   Source/CommonLibs/NonDF/lua-4.0.1/src/ltests.c
   Source/CommonLibs/NonDF/lua-4.0.1/src/ltm.c 
   Source/CommonLibs/NonDF/lua-4.0.1/src/lundump.c 
   Source/CommonLibs/NonDF/lua-4.0.1/src/lvm.c 
   Source/CommonLibs/NonDF/lua-4.0.1/src/lzio.c
)
target_include_directories(liblua PUBLIC 
   Source/CommonLibs/NonDF/lua-4.0.1/src
   Source/CommonLibs/NonDF/lua-4.0.1/include
)

# Insert new source files here.
add_executable(li-po
   Source/CommonLibs/NonDF/ISACTEng/SoundQueue.cpp
   Source/CommonLibs/NonDF/ISACTEng/Array.cpp
   Source/CommonLibs/NonDF/ISACTEng/Translator.cpp
   Source/CommonLibs/NonDF/ISACTEng/SoundRandomizer.cpp

   Source/CommonLibs/NonDF/AudioDrv/AudioDrv.cpp
   Source/CommonLibs/NonDF/AudioDrv/Buffer.cpp
   Source/CommonLibs/NonDF/AudioDrv/Source.cpp
   Source/CommonLibs/NonDF/AudioDrv/main.cpp
   Source/CommonLibs/NonDF/AudioDrv/AudioISACTPS.cpp
   Source/CommonLibs/NonDF/AudioDrv/AudioISACT.cpp

   Source/CommonLibs/DFUtil/EFile.cpp
   Source/CommonLibs/DFUtil/EStaticList.cpp
   Source/CommonLibs/DFUtil/Heap.cpp
   Source/CommonLibs/DFUtil/EArray.cpp
   Source/CommonLibs/DFUtil/EBitmap.cpp
   Source/CommonLibs/DFUtil/Directory.cpp
   Source/CommonLibs/DFUtil/EFileCache.cpp
   Source/CommonLibs/DFUtil/ELogFile.cpp
   Source/CommonLibs/DFUtil/EPackageFile.cpp
   Source/CommonLibs/DFUtil/Timing.cpp
   Source/CommonLibs/DFUtil/EPackFile.cpp
   Source/CommonLibs/DFUtil/ETga.cpp
   Source/CommonLibs/DFUtil/EBufferedFile.cpp
   Source/CommonLibs/DFUtil/EWin32File.cpp
   Source/CommonLibs/DFUtil/EMemStack.cpp
   Source/CommonLibs/DFUtil/EGameFile.cpp
   Source/CommonLibs/DFUtil/BitArray.cpp
   Source/CommonLibs/DFUtil/ErrorManager.cpp
   Source/CommonLibs/DFUtil/EStream.cpp
   Source/CommonLibs/DFUtil/EFileManager.cpp
   Source/CommonLibs/DFUtil/EStaticCache.cpp
   Source/CommonLibs/DFUtil/HashTable.cpp
   Source/CommonLibs/DFUtil/DFUnixCompat.cpp
   Source/CommonLibs/DFUtil/String.cpp
   Source/CommonLibs/DFUtil/HandleAllocator.cpp
   Source/CommonLibs/DFUtil/Profiler.cpp
   Source/CommonLibs/DFUtil/EErrorManager.cpp

   Source/CommonLibs/DFMath/MathGeneral.cpp
   Source/CommonLibs/DFMath/Matrix.cpp
   Source/CommonLibs/DFMath/Random.cpp
   Source/CommonLibs/DFMath/BoundingBox.cpp
   Source/CommonLibs/DFMath/Vector.cpp
   Source/CommonLibs/DFMath/Intersect.cpp
   Source/CommonLibs/DFMath/Covariance.cpp
   Source/CommonLibs/DFMath/Octree.cpp
   Source/CommonLibs/DFMath/Curve.cpp

   Source/CommonLibs/DirectX/SDLInput.cpp

   Source/CommonLibs/DFSound/ISACTSoundManager.cpp

   Source/CommonLibs/DFNet/DFNet.cpp

   Source/CommonLibs/DFGraphics/Palette.cpp
   Source/CommonLibs/DFGraphics/Color.cpp
   Source/CommonLibs/DFGraphics/Renderer.cpp
   Source/CommonLibs/DFGraphics/Texture.cpp
   Source/CommonLibs/DFGraphics/Vertex.cpp
   Source/CommonLibs/DFGraphics/OpenGLGraphics.cpp

   Source/game/luatest/Entity/InvisibilityEntity.cpp
   Source/game/luatest/Entity/TeleKinesisEntity.cpp
   Source/game/luatest/Entity/KnapsackEntity.cpp
   Source/game/luatest/Entity/MMGravityEntity.cpp
   Source/game/luatest/Entity/TrampolineEntity.cpp
   Source/game/luatest/Entity/FirestartingEntity.cpp
   Source/game/luatest/Entity/PlayerEntity.cpp
   Source/game/luatest/Entity/TightropeEntity.cpp

   Source/game/luatest/ScriptVM/ScriptThread.cpp
   Source/game/luatest/ScriptVM/Script_Debug.cpp
   Source/game/luatest/ScriptVM/ScriptMessage.cpp
   Source/game/luatest/ScriptVM/ScriptVM.cpp
   Source/game/luatest/ScriptVM/Script_Physics.cpp
   Source/game/luatest/ScriptVM/ScriptAPI.cpp

   Source/game/luatest/DebugServer/DebugCommands.cpp
   Source/game/luatest/DebugServer/Transport.cpp
   Source/game/luatest/DebugServer/ScriptProfiler.cpp
   Source/game/luatest/DebugServer/BreakpointManager.cpp
   Source/game/luatest/DebugServer/DebugManager.cpp

   Source/game/luatest/Path/ESplineController.cpp
   Source/game/luatest/Path/EPathManager.cpp

   Source/game/luatest/PathAI/EPathAIManager.cpp
   Source/game/luatest/PathAI/EFlock.cpp

   Source/game/luatest/Game/ControlHandler.cpp
   Source/game/luatest/Game/SaveLoadGame.cpp
   Source/game/luatest/Game/TrapezeControlHandler.cpp
   Source/game/luatest/Game/CanoeControlHandler.cpp
   Source/game/luatest/Game/PlayerControlHandler.cpp
   Source/game/luatest/Game/ScriptCamera.cpp
   Source/game/luatest/Game/BallControlHandler.cpp
   Source/game/luatest/Game/GameRender.cpp
   Source/game/luatest/Game/UIMenu.cpp
   Source/game/luatest/Game/TightropeControlHandler.cpp
   Source/game/luatest/Game/GameShader.cpp
   Source/game/luatest/Game/UIKeypad.cpp
   Source/game/luatest/Game/UIPCKeyboardBindings.cpp
   Source/game/luatest/Game/TKControlHandler.cpp
   Source/game/luatest/Game/ScriptControlHandler.cpp
   Source/game/luatest/Game/SplashScreen.cpp
   Source/game/luatest/Game/LoadingScreen.cpp
   Source/game/luatest/Game/UIPCDisplayOptions.cpp
   Source/game/luatest/Game/RailCamera.cpp
   Source/game/luatest/Game/BubbleControlHandler.cpp
   Source/game/luatest/Game/Gameplaylogger.cpp
   Source/game/luatest/Game/PCGameApp.cpp
   Source/game/luatest/Game/UIIngameMenu.cpp
   Source/game/luatest/Game/DialogChoiceControlHandler.cpp
   Source/game/luatest/Game/GameSettings.cpp
   Source/game/luatest/Game/GameApp.cpp
   Source/game/luatest/Game/UI.cpp
   Source/game/luatest/Game/Camera.cpp
   Source/game/luatest/Game/CantileverControlHandler.cpp
   Source/game/luatest/Game/UIWidget.cpp
   Source/game/luatest/Game/DebugScreen.cpp
   Source/game/luatest/Game/LadderControlHandler.cpp
   Source/game/luatest/Game/GameInit.cpp

   Source/game/luatest/DialogManager/DialogManager.cpp

   Source/game/luatest/Event/EEventAnimController.cpp
   Source/game/luatest/Event/EEventAnim.cpp
   Source/game/luatest/Event/EEventAnimChannel.cpp
   Source/game/luatest/Event/EEventAnimManager.cpp
   Source/game/luatest/RTEngine/EBlendShape.cpp
   Source/game/luatest/RTEngine/AnimManager.cpp
   Source/game/luatest/RTEngine/Halo.cpp
   Source/game/luatest/RTEngine/CollisionTree.cpp
   Source/game/luatest/RTEngine/LineParticleEntity.cpp
   Source/game/luatest/RTEngine/WaterManager.cpp
   Source/game/luatest/RTEngine/EBlendAnim.cpp
   Source/game/luatest/RTEngine/AnimAffector.cpp
   Source/game/luatest/RTEngine/FreezeManager.cpp
   Source/game/luatest/RTEngine/NavMesh.cpp
   Source/game/luatest/RTEngine/Trigger.cpp
   Source/game/luatest/RTEngine/PhysicsMove.cpp
   Source/game/luatest/RTEngine/EBlendAnimController.cpp
   Source/game/luatest/RTEngine/Mesh.cpp
   Source/game/luatest/RTEngine/Domain.cpp
   Source/game/luatest/RTEngine/Decal.cpp
   Source/game/luatest/RTEngine/EBlendAnimChannel.cpp
   Source/game/luatest/RTEngine/Font.cpp
   Source/game/luatest/RTEngine/Joint.cpp
   Source/game/luatest/RTEngine/Light.cpp
   Source/game/luatest/RTEngine/PlayerPhysics.cpp
   Source/game/luatest/RTEngine/RenderSpline.cpp
   Source/game/luatest/RTEngine/EBlendTarget.cpp
   Source/game/luatest/RTEngine/GameTexture.cpp
   Source/game/luatest/RTEngine/AnimQueue.cpp
   Source/game/luatest/RTEngine/VisibilityTree.cpp
   Source/game/luatest/RTEngine/MeshEntity.cpp
   Source/game/luatest/RTEngine/Text3D.cpp
   Source/game/luatest/RTEngine/EBlendAnimManager.cpp
   Source/game/luatest/RTEngine/SkelAnim2.cpp
   Source/game/luatest/RTEngine/Model.cpp
   Source/game/luatest/RTEngine/RenderPatch.cpp
   Source/game/luatest/RTEngine/Scene.cpp
   Source/game/luatest/RTEngine/LightTrail.cpp
   Source/game/luatest/RTEngine/TextureManager.cpp
   Source/game/luatest/RTEngine/ParticleEmitterEntity.cpp
   Source/game/luatest/RTEngine/Entity.cpp
   Source/game/luatest/RTEngine/Physics.cpp
   Source/game/luatest/RTEngine/CollisionManager.cpp
   Source/game/luatest/RTEngine/MeshManager.cpp
   Source/game/luatest/RTEngine/LineCollision.cpp
   Source/game/luatest/RTEngine/SkelAnimShared.cpp
   Source/game/luatest/RTEngine/EBlendFragment.cpp
   Source/game/luatest/RTEngine/Sprite.cpp
   Source/game/luatest/RTEngine/ActionTable.cpp
   Source/game/luatest/RTEngine/Skeleton.cpp
   Source/game/luatest/RTEngine/MeshFrag.cpp

   Source/game/luatest/DFConsole.cpp
   Source/game/luatest/UnixMain.cpp
)

target_include_directories(li-po PUBLIC 
   Source/CommonLibs 
   Source/game/luatest
   Source/CommonLibs/NonDF/mojoAL
   Source/CommonLibs/NonDF/lua-4.0.1/include
)

if(TARGET SDL2::SDL2main)
   # SDL2main has an implicit dependency on SDL2 functions, so it MUST be added before SDL2::SDL2 (or SDL2::SDL2-static)
   target_link_libraries(li-po PRIVATE SDL2::SDL2main)
endif()

target_link_libraries(li-po PRIVATE liblua mojoal mojoshader SDL2::SDL2)
