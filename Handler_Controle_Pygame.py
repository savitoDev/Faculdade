"""
Este código é um "Handler" de controle bluetooth mirado para controles de XBOX, seja ele um 360 ou um One S. Tanto faz.
(INSTALE A BIBLIOTECA PYGAME)
Salve este arquivo em seu computador, e execute-o onde for. De preferência no Powershell.

"""

import pygame
import time

pygame.init()
pygame.joystick.init()

if pygame.joystick.get_count() == 0:
    print("Erro: Controle não detectado. Tente novamente.")
    pygame.quit()
    exit()

joystick = pygame.joystick.Joystick(0)
joystick.init()

print("-" * 40)
print(f"Controle detectado: {joystick.get_name()}")
print(f"    Botões detectados: {joystick.get_numbuttons()}")
print(f"    Eixos (Joystick/Triggers) detectados: {joystick.get_numaxes()}")
print("-" * 40)
print("Pressone e mova botões/eixos para ver os valores! (Ctrl+C para sair)")

try:
    while True:
        pygame.event.pump()

        for i in range(joystick.get_numbuttons()):
            if joystick.get_button(i):
                print(f"Botão pressionado: {i}")
        
        for i in range(joystick.get_numaxes()):
            axis_value = joystick.get_axis(i)
            if abs(axis_value) > 0.1:
                print(f"Eixo {i}: {axis_value:.2f}")

        time.sleep(0.05)

except KeyboardInterrupt:
    print("\nTeste encerrado")
finally:
    pygame.quit()
