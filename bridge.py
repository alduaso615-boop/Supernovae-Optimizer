import subprocess
import time

def run_luau_logic():
    try:
        # Ejecuta el script de Luau y captura la salida
        result = subprocess.check_output(["luau", "logic.luau"]).decode("utf-8")
        # Guarda el resultado en un archivo temporal que Java leerá
        with open("stats.txt", "w") as f:
            f.write(result)
    except Exception as e:
        print(f"Error en Luau: {e}")

while True:
    run_luau_logic()
    time.sleep(1) # Actualiza cada segundo