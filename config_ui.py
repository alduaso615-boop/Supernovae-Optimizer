import tkinter as tk
from tkinter import colorchooser

def escoger_color():
    color = colorchooser.askcolor(title="Selecciona el color del Overlay")
    if color[0]:
        rgb = color[0]
        # Guardamos en el archivo que Java está leyendo
        with open("color.txt", "w") as f:
            f.write(f"{int(rgb[0])},{int(rgb[1])},{int(rgb[2])}")
        print(f"Color actualizado: {rgb}")

root = tk.Tk()
root.title("Supernovae Color Picker")
root.geometry("200x100")

btn = tk.Button(root, text="Cambiar Color Overlay", command=escoger_color)
btn.pack(expand=True)

root.mainloop()