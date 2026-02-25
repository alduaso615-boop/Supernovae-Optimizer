-- Script de Luau para procesar datos de latencia
function calculate_offset(ping)
    return ping + (math.random(-1, 1) * 0.5)
end

print("Luau Engine v1.0")
print("Compensacion de offset: " .. calculate_offset(15) .. "ms")