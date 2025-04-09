cmake_minimum_required(VERSION 3.0...3.10)
project(li-po
   VERSION 0.1.0
   LANGUAGES C CXX
)
set (CMAKE_CXX_STANDARD 98)

add_subdirectory(Source/CommonLibs/NonDF/SDL2 EXCLUDE_FROM_ALL)
add_subdirectory(Source/CommonLibs/NonDF/mojoshader EXCLUDE_FROM_ALL)

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

add_library(mojoal STATIC Source/CommonLibs/NonDF/mojoAL/mojoal.c)
target_include_directories(mojoal PUBLIC 
   Source/CommonLibs/NonDF/lua-4.0.1/include
   Source/CommonLibs/NonDF/lua-4.0.1/include/AL
)

# Insert new source files here.
add_executable(li-po
   Source/CommonLibs/NonDF/ISACTEng/SoundQueue.cpp
   Source/CommonLibs/NonDF/ISACTEng/SoundRandomizer.h
   Source/CommonLibs/NonDF/ISACTEng/Array.cpp
   Source/CommonLibs/NonDF/ISACTEng/Translator.cpp
   Source/CommonLibs/NonDF/ISACTEng/Translator.h
   Source/CommonLibs/NonDF/ISACTEng/Array.h
   Source/CommonLibs/NonDF/ISACTEng/SoundRandomizer.cpp
   Source/CommonLibs/NonDF/ISACTEng/SoundQueue.h

   Source/CommonLibs/NonDF/AudioDrv/AudioDrv.cpp
   Source/CommonLibs/NonDF/AudioDrv/Source.h
   Source/CommonLibs/NonDF/AudioDrv/Buffer.cpp
   Source/CommonLibs/NonDF/AudioDrv/Source.cpp
   Source/CommonLibs/NonDF/AudioDrv/AudioISACTPS.h
   Source/CommonLibs/NonDF/AudioDrv/AudioISACT.h
   Source/CommonLibs/NonDF/AudioDrv/main.cpp
   Source/CommonLibs/NonDF/AudioDrv/AudioDrv.h
   Source/CommonLibs/NonDF/AudioDrv/AudioISACTPS.cpp
   Source/CommonLibs/NonDF/AudioDrv/Buffer.h
   Source/CommonLibs/NonDF/AudioDrv/main.h
   Source/CommonLibs/NonDF/AudioDrv/AudioISACT.cpp

   Source/CommonLibs/DFUtil/EStream.h
   Source/CommonLibs/DFUtil/EGameFile.h
   Source/CommonLibs/DFUtil/Heap.h
   Source/CommonLibs/DFUtil/EBufferedFile.h
   Source/CommonLibs/DFUtil/EFile.cpp
   Source/CommonLibs/DFUtil/EStaticList.cpp
   Source/CommonLibs/DFUtil/Heap.cpp
   Source/CommonLibs/DFUtil/String.h
   Source/CommonLibs/DFUtil/EArray.cpp
   Source/CommonLibs/DFUtil/EBitmap.cpp
   Source/CommonLibs/DFUtil/Directory.cpp
   Source/CommonLibs/DFUtil/EFileCache.cpp
   Source/CommonLibs/DFUtil/EFileManager.h
   Source/CommonLibs/DFUtil/EFileCache.h
   Source/CommonLibs/DFUtil/ELogFile.h
   Source/CommonLibs/DFUtil/ELogFile.cpp
   Source/CommonLibs/DFUtil/EPackageFile.cpp
   Source/CommonLibs/DFUtil/EStaticList.h
   Source/CommonLibs/DFUtil/EMemStack.h
   Source/CommonLibs/DFUtil/Timing.cpp
   Source/CommonLibs/DFUtil/EStaticCache.h
   Source/CommonLibs/DFUtil/Directory.h
   Source/CommonLibs/DFUtil/HashTable.h
   Source/CommonLibs/DFUtil/EPackFile.cpp
   Source/CommonLibs/DFUtil/Profiler.h
   Source/CommonLibs/DFUtil/ETga.cpp
   Source/CommonLibs/DFUtil/EBufferedFile.cpp
   Source/CommonLibs/DFUtil/EWin32File.cpp
   Source/CommonLibs/DFUtil/EBitmap.h
   Source/CommonLibs/DFUtil/EWin32File.h
   Source/CommonLibs/DFUtil/EMemStack.cpp
   Source/CommonLibs/DFUtil/BitArray.h
   Source/CommonLibs/DFUtil/EPackFile.h
   Source/CommonLibs/DFUtil/EGameFile.cpp
   Source/CommonLibs/DFUtil/ErrorManager.h
   Source/CommonLibs/DFUtil/Timing.h
   Source/CommonLibs/DFUtil/BitArray.cpp
   Source/CommonLibs/DFUtil/ErrorManager.cpp
   Source/CommonLibs/DFUtil/HandleAllocator.h
   Source/CommonLibs/DFUtil/EStream.cpp
   Source/CommonLibs/DFUtil/EFileManager.cpp
   Source/CommonLibs/DFUtil/EFile.h
   Source/CommonLibs/DFUtil/EStaticCache.cpp
   Source/CommonLibs/DFUtil/ETga.h
   Source/CommonLibs/DFUtil/EPackageFile.h
   Source/CommonLibs/DFUtil/HashTable.cpp
   Source/CommonLibs/DFUtil/DFUnixCompat.cpp
   Source/CommonLibs/DFUtil/String.cpp
   Source/CommonLibs/DFUtil/DFUnixCompat.h
   Source/CommonLibs/DFUtil/EArray.h
   Source/CommonLibs/DFUtil/HandleAllocator.cpp
   Source/CommonLibs/DFUtil/Profiler.cpp

   Source/CommonLibs/DFMath/BoundingBox.h
   Source/CommonLibs/DFMath/MathGeneral.cpp
   Source/CommonLibs/DFMath/Covariance.h
   Source/CommonLibs/DFMath/Octree.h
   Source/CommonLibs/DFMath/Matrix.cpp
   Source/CommonLibs/DFMath/Random.cpp
   Source/CommonLibs/DFMath/Curve.h
   Source/CommonLibs/DFMath/BoundingBox.cpp
   Source/CommonLibs/DFMath/Random.h
   Source/CommonLibs/DFMath/Vector.cpp
   Source/CommonLibs/DFMath/Intersect.cpp
   Source/CommonLibs/DFMath/MathGeneral.h
   Source/CommonLibs/DFMath/Covariance.cpp
   Source/CommonLibs/DFMath/Vector.h
   Source/CommonLibs/DFMath/Matrix.h
   Source/CommonLibs/DFMath/Octree.cpp
   Source/CommonLibs/DFMath/Intersect.h
   Source/CommonLibs/DFMath/Curve.cpp

   Source/CommonLibs/DirectX/SDLInput.h
   Source/CommonLibs/DirectX/SDLInput.cpp

   Source/CommonLibs/DFSound/ISACTSoundManager.h
   Source/CommonLibs/DFSound/ISACTSoundManager.cpp

   Source/CommonLibs/DFNet/DFNet.cpp
   Source/CommonLibs/DFNet/DFNet.h

   Source/CommonLibs/DFGraphics/Palette.cpp
   Source/CommonLibs/DFGraphics/Color.h
   Source/CommonLibs/DFGraphics/Palette.h
   Source/CommonLibs/DFGraphics/ERenderer.h
   Source/CommonLibs/DFGraphics/Renderer.h
   Source/CommonLibs/DFGraphics/Color.cpp
   Source/CommonLibs/DFGraphics/Renderer.cpp
   Source/CommonLibs/DFGraphics/Texture.cpp
   Source/CommonLibs/DFGraphics/EOpenGLRenderer.h
   Source/CommonLibs/DFGraphics/Vertex.h
   Source/CommonLibs/DFGraphics/Vertex.cpp
   Source/CommonLibs/DFGraphics/OpenGLGraphics.cpp
   Source/CommonLibs/DFGraphics/Texture.h

   Source/game/luatest/Entity/TeleKinesisEntity.h
   Source/game/luatest/Entity/InvisibilityEntity.cpp
   Source/game/luatest/Entity/TeleKinesisEntity.cpp
   Source/game/luatest/Entity/FirestartingEntity.h
   Source/game/luatest/Entity/KnapsackEntity.cpp
   Source/game/luatest/Entity/MMGravityEntity.h
   Source/game/luatest/Entity/TightropeEntity.h
   Source/game/luatest/Entity/MMGravityEntity.cpp
   Source/game/luatest/Entity/TrampolineEntity.h
   Source/game/luatest/Entity/InvisibilityEntity.h
   Source/game/luatest/Entity/TrampolineEntity.cpp
   Source/game/luatest/Entity/PlayerEntity.h
   Source/game/luatest/Entity/FirestartingEntity.cpp
   Source/game/luatest/Entity/KnapsackEntity.h
   Source/game/luatest/Entity/PlayerEntity.cpp
   Source/game/luatest/Entity/TightropeEntity.cpp

   Source/game/luatest/ScriptVM/ScriptThread.cpp
   Source/game/luatest/ScriptVM/Script_Debug.cpp
   Source/game/luatest/ScriptVM/ScriptMessage.cpp
   Source/game/luatest/ScriptVM/ScriptVM.cpp
   Source/game/luatest/ScriptVM/Script_Debug.h
   Source/game/luatest/ScriptVM/Script_Physics.cpp
   Source/game/luatest/ScriptVM/ScriptMessage.h
   Source/game/luatest/ScriptVM/ScriptAPI.cpp
   Source/game/luatest/ScriptVM/ScriptAPI.h
   Source/game/luatest/ScriptVM/ScriptThread.h
   Source/game/luatest/ScriptVM/Script_Physics.h
   Source/game/luatest/ScriptVM/ScriptVM.h

   Source/game/luatest/DebugServer/DebugManager.h
   Source/game/luatest/DebugServer/DebugCommands.cpp
   Source/game/luatest/DebugServer/ScriptProfiler.h
   Source/game/luatest/DebugServer/Transport.cpp
   Source/game/luatest/DebugServer/BreakpointManager.h
   Source/game/luatest/DebugServer/Transport.h
   Source/game/luatest/DebugServer/ScriptProfiler.cpp
   Source/game/luatest/DebugServer/BreakpointManager.cpp
   Source/game/luatest/DebugServer/DebugManager.cpp
   Source/game/luatest/DebugServer/DebugCommands.h

   Source/game/luatest/Path/ESplineController.h
   Source/game/luatest/Path/ESplineController.cpp
   Source/game/luatest/Path/EPathManager.h
   Source/game/luatest/Path/EPathManager.cpp

   Source/game/luatest/PathAI/EPathAIManager.h
   Source/game/luatest/PathAI/EPathAIManager.cpp
   Source/game/luatest/PathAI/EFlock.h
   Source/game/luatest/PathAI/EFlock.cpp

   Source/game/luatest/Game/SplashScreen.h
   Source/game/luatest/Game/ControlHandler.cpp
   Source/game/luatest/Game/BubbleControlHandler.h
   Source/game/luatest/Game/LadderControlHandler.h
   Source/game/luatest/Game/SaveLoadGame.cpp
   Source/game/luatest/Game/TrapezeControlHandler.cpp
   Source/game/luatest/Game/CanoeControlHandler.cpp
   Source/game/luatest/Game/ScriptCamera.h
   Source/game/luatest/Game/GameInit.h
   Source/game/luatest/Game/PlayerControlHandler.cpp
   Source/game/luatest/Game/TrapezeControlHandler.h
   Source/game/luatest/Game/PlayerControlHandler.h
   Source/game/luatest/Game/ScriptCamera.cpp
   Source/game/luatest/Game/BallControlHandler.cpp
   Source/game/luatest/Game/GameApp.h
   Source/game/luatest/Game/GameRender.cpp
   Source/game/luatest/Game/SaveLoadGame.h
   Source/game/luatest/Game/UIMenu.cpp
   Source/game/luatest/Game/TightropeControlHandler.cpp
   Source/game/luatest/Game/RailCamera.h
   Source/game/luatest/Game/GameShader.cpp
   Source/game/luatest/Game/UIKeypad.cpp
   Source/game/luatest/Game/UIMenu.h
   Source/game/luatest/Game/UIPCKeyboardBindings.cpp
   Source/game/luatest/Game/CanoeControlHandler.h
   Source/game/luatest/Game/GameShader.h
   Source/game/luatest/Game/GameSettings.h
   Source/game/luatest/Game/LoadingScreen.h
   Source/game/luatest/Game/TKControlHandler.cpp
   Source/game/luatest/Game/GameRender.h
   Source/game/luatest/Game/ScriptControlHandler.cpp
   Source/game/luatest/Game/SplashScreen.cpp
   Source/game/luatest/Game/LoadingScreen.cpp
   Source/game/luatest/Game/Camera.h
   Source/game/luatest/Game/UI.h
   Source/game/luatest/Game/UIPCDisplayOptions.cpp
   Source/game/luatest/Game/RailCamera.cpp
   Source/game/luatest/Game/UIIngameMenu.h
   Source/game/luatest/Game/PCGameApp.h
   Source/game/luatest/Game/TightropeControlHandler.h
   Source/game/luatest/Game/BubbleControlHandler.cpp
   Source/game/luatest/Game/Gameplaylogger.cpp
   Source/game/luatest/Game/UIKeypad.h
   Source/game/luatest/Game/UIPCDisplayOptions.h
   Source/game/luatest/Game/PCGameApp.cpp
   Source/game/luatest/Game/UIIngameMenu.cpp
   Source/game/luatest/Game/ScriptControlHandler.h
   Source/game/luatest/Game/DialogChoiceControlHandler.cpp
   Source/game/luatest/Game/GameSettings.cpp
   Source/game/luatest/Game/UIPCKeyboardBindings.h
   Source/game/luatest/Game/UIWidget.h
   Source/game/luatest/Game/GameApp.cpp
   Source/game/luatest/Game/DialogChoiceControlHandler.h
   Source/game/luatest/Game/ControlHandler.h
   Source/game/luatest/Game/UI.cpp
   Source/game/luatest/Game/Camera.cpp
   Source/game/luatest/Game/BallControlHandler.h
   Source/game/luatest/Game/Gameplaylogger.h
   Source/game/luatest/Game/DebugScreen.h
   Source/game/luatest/Game/CantileverControlHandler.cpp
   Source/game/luatest/Game/CantileverControlHandler.h
   Source/game/luatest/Game/TKControlHandler.h
   Source/game/luatest/Game/UIWidget.cpp
   Source/game/luatest/Game/DebugScreen.cpp
   Source/game/luatest/Game/LadderControlHandler.cpp
   Source/game/luatest/Game/GameInit.cpp

   Source/game/luatest/DialogManager/DialogManager.h
   Source/game/luatest/DialogManager/DialogManager.cpp

   Source/game/luatest/Event/EEventAnimManager.h
   Source/game/luatest/Event/EEventAnimController.cpp
   Source/game/luatest/Event/EEventAnim.cpp
   Source/game/luatest/Event/EEventAnimController.h
   Source/game/luatest/Event/EEventAnimChannel.cpp
   Source/game/luatest/Event/EEventAnimChannel.h
   Source/game/luatest/Event/EEventAnim.h
   Source/game/luatest/Event/EEventAnimManager.cpp

   Source/game/luatest/RTEngine/EBlendShape.cpp
   Source/game/luatest/RTEngine/Text3D.h
   Source/game/luatest/RTEngine/ParticleEmitterEntity.h
   Source/game/luatest/RTEngine/AnimManager.cpp
   Source/game/luatest/RTEngine/EBlendAnim.h
   Source/game/luatest/RTEngine/RenderSpline.h
   Source/game/luatest/RTEngine/Halo.cpp
   Source/game/luatest/RTEngine/CollisionTree.cpp
   Source/game/luatest/RTEngine/LineParticleEntity.cpp
   Source/game/luatest/RTEngine/WaterManager.cpp
   Source/game/luatest/RTEngine/EBlendFragment.h
   Source/game/luatest/RTEngine/Physics.h
   Source/game/luatest/RTEngine/EBlendAnim.cpp
   Source/game/luatest/RTEngine/AnimAffector.cpp
   Source/game/luatest/RTEngine/Scene.h
   Source/game/luatest/RTEngine/FreezeManager.cpp
   Source/game/luatest/RTEngine/NavMesh.cpp
   Source/game/luatest/RTEngine/Trigger.cpp
   Source/game/luatest/RTEngine/PhysicsMove.cpp
   Source/game/luatest/RTEngine/EBlendAnimManager.h
   Source/game/luatest/RTEngine/EBlendShape.h
   Source/game/luatest/RTEngine/EBlendAnimController.cpp
   Source/game/luatest/RTEngine/AnimManager.h
   Source/game/luatest/RTEngine/Mesh.cpp
   Source/game/luatest/RTEngine/Domain.cpp
   Source/game/luatest/RTEngine/FreezeManager.h
   Source/game/luatest/RTEngine/SkelAnimShared.h
   Source/game/luatest/RTEngine/Light.h
   Source/game/luatest/RTEngine/Decal.cpp
   Source/game/luatest/RTEngine/EBlendAnimChannel.cpp
   Source/game/luatest/RTEngine/CollisionManager.h
   Source/game/luatest/RTEngine/Font.cpp
   Source/game/luatest/RTEngine/Joint.cpp
   Source/game/luatest/RTEngine/Light.cpp
   Source/game/luatest/RTEngine/PlayerPhysics.cpp
   Source/game/luatest/RTEngine/RenderSpline.cpp
   Source/game/luatest/RTEngine/EBlendTarget.cpp
   Source/game/luatest/RTEngine/GameTexture.cpp
   Source/game/luatest/RTEngine/Entity.h
   Source/game/luatest/RTEngine/AnimQueue.cpp
   Source/game/luatest/RTEngine/Sprite.h
   Source/game/luatest/RTEngine/VisibilityTree.cpp
   Source/game/luatest/RTEngine/MeshManager.h
   Source/game/luatest/RTEngine/PhysicsMove.h
   Source/game/luatest/RTEngine/MeshEntity.h
   Source/game/luatest/RTEngine/LineParticleEntity.h
   Source/game/luatest/RTEngine/MeshEntity.cpp
   Source/game/luatest/RTEngine/Text3D.cpp
   Source/game/luatest/RTEngine/TextureManager.h
   Source/game/luatest/RTEngine/EBlendAnimController.h
   Source/game/luatest/RTEngine/EBlendAnimManager.cpp
   Source/game/luatest/RTEngine/Font.h
   Source/game/luatest/RTEngine/SkelAnim2.cpp
   Source/game/luatest/RTEngine/CollisionTree.h
   Source/game/luatest/RTEngine/Model.cpp
   Source/game/luatest/RTEngine/RenderPatch.cpp
   Source/game/luatest/RTEngine/Scene.cpp
   Source/game/luatest/RTEngine/LightTrail.h
   Source/game/luatest/RTEngine/LightTrail.cpp
   Source/game/luatest/RTEngine/TextureManager.cpp
   Source/game/luatest/RTEngine/Joint.h
   Source/game/luatest/RTEngine/GameTexture.h
   Source/game/luatest/RTEngine/ParticleEmitterEntity.cpp
   Source/game/luatest/RTEngine/SkelAnim2.h
   Source/game/luatest/RTEngine/AnimAffector.h
   Source/game/luatest/RTEngine/Entity.cpp
   Source/game/luatest/RTEngine/Physics.cpp
   Source/game/luatest/RTEngine/Trigger.h
   Source/game/luatest/RTEngine/VisibilityTree.h
   Source/game/luatest/RTEngine/MeshFrag.h
   Source/game/luatest/RTEngine/CollisionManager.cpp
   Source/game/luatest/RTEngine/AnimQueue.h
   Source/game/luatest/RTEngine/Domain.h
   Source/game/luatest/RTEngine/WaterManager.h
   Source/game/luatest/RTEngine/RenderPatch.h
   Source/game/luatest/RTEngine/MeshManager.cpp
   Source/game/luatest/RTEngine/LineCollision.cpp
   Source/game/luatest/RTEngine/SkelAnimShared.cpp
   Source/game/luatest/RTEngine/EBlendFragment.cpp
   Source/game/luatest/RTEngine/EBlendTarget.h
   Source/game/luatest/RTEngine/Halo.h
   Source/game/luatest/RTEngine/EBlendAnimChannel.h
   Source/game/luatest/RTEngine/Sprite.cpp
   Source/game/luatest/RTEngine/Mesh.h
   Source/game/luatest/RTEngine/Model.h
   Source/game/luatest/RTEngine/LineCollision.h
   Source/game/luatest/RTEngine/ActionTable.h
   Source/game/luatest/RTEngine/NavMesh.h
   Source/game/luatest/RTEngine/ActionTable.cpp
   Source/game/luatest/RTEngine/Skeleton.cpp
   Source/game/luatest/RTEngine/Skeleton.h
   Source/game/luatest/RTEngine/PlayerPhysics.h
   Source/game/luatest/RTEngine/MeshFrag.cpp
   Source/game/luatest/RTEngine/Decal.h

   Source/game/luatest/DFConsole.h
   Source/game/luatest/DFConsole.cpp
   Source/game/luatest/UnixMain.cpp
)

target_include_directories(li-po PUBLIC 
   Source/CommonLibs 
   Source/game/luatest
   Source/CommonLibs/NonDF/mojoAL/AL
   Source/CommonLibs/NonDF/lua-4.0.1/include
)

if(TARGET SDL2::SDL2main)
   # SDL2main has an implicit dependency on SDL2 functions, so it MUST be added before SDL2::SDL2 (or SDL2::SDL2-static)
   target_link_libraries(li-po PRIVATE SDL2::SDL2main)
endif()

target_link_libraries(li-po PRIVATE liblua mojoal mojoshader SDL2::SDL2)
