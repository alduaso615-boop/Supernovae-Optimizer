@echo off
title Lanzador Supernovae 99.88%
color 0a
cls

echo ============================================
echo    INICIANDO MODO SUPERNOVAE (MODO DIOS)
echo ============================================

:: 1. Limpieza de cache DNS y RAM (Standby list)
echo [+] Limpiando basura del sistema...
ipconfig /flushdns >nul
start /b "" "SupernovaeOptimizer.exe"

:: 2. Iniciar el Overlay de FPS
echo [+] Activando Overlay transparente...
start /b "" "SupernovaeOverlay.exe"

:: 3. Abrir osu! (Asegúrate de que la ruta sea la correcta)

:: Si tu osu! esta en otra carpeta, cambia la ruta abajo:


echo ============================================
echo    ¡TODO LISTO! VE POR ESE 99.88%% ACC
echo ============================================
timeout /t 5
exit