#Commands to run from outside your IDE to invoke the builds/compiles properly

#CompileEngine
..\\Engine\\Build\\BatchFiles\\Build.bat -Target="UnrealEditor Win64 Development" -Target="ShaderCompileWorker Win64 Development -Quiet" -WaitMutex -FromMsBuild

#CompileGame
..\\Engine\\Build\\BatchFiles\\Build.bat -Target="YourGameEditor Win64 Development" -Target="ShaderCompileWorker Win64 Development -Quiet" -WaitMutex -FromMsBuild

#RunGame, call from within your Game folder, with profiling
..\\Engine\\Binaries\\Win64\\UnrealEditor.exe YourGame.uproject -NetTrace=2 -tracehost=localhost -trace=net -log -VERBOSE

#RunGame, call from within your Game folder, withut profiling
..\\Engine\\Binaries\\Win64\\UnrealEditor.exe YourGame.uproject
