@echo off
title SUPERNOVAE MULTI-ENGINE LAUNCHER
color 0b

echo [+] Iniciando Motores...
start /b "" "SupernovaeOptimizer.exe"
start /b "" "pythonw bridge.py"
start /b "" "java OverlayJava"

echo [+] Limpiando Standby List...
ipconfig /flushdns >nul

echo [+] ¡A por el 99.88%% ACC!
exit