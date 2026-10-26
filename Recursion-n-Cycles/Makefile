# ============================================================================
# Makefile - Estructura de Datos, Unidad II
#
# Estructura del proyecto:
#   include/         -> algoritmos.h, globals.inc, menu.h
#   src/             -> main.c, algoritmos.c, menu.c
#   src/asm/         -> fibonacci.s, factorial.s, mcd.s
#
# Uso:
#   make          -> compila todo en build/programa
#   make run      -> ejecuta build/programa
#   make clean    -> borra build/
# ============================================================================

# --- Herramientas -----------------------------------------------------------
CC      := gcc
AS      := as
LD      := gcc

# --- Directorios ------------------------------------------------------------
BUILD   := build
INCLUDE := include
SRC     := src
ASMDIR  := $(SRC)/asm

# --- Banderas ---------------------------------------------------------------
# -no-pie: los .s usan direccionamiento absoluto (ej. "mov eax, [var_a]")
# --allow-multiple-definition: globals.inc se incluye vía .include en cada .s,
#   por lo que varios .o definen los mismos símbolos (iteraciones, recursion,
#   resultado, etc.). Se permite el duplicado y el linker elige uno.
CFLAGS   := -Wall -Wextra -I"$(INCLUDE)" -g -MMD -MP
ASFLAGS  := --64 -g
LDFLAGS  := -no-pie -Wl,--allow-multiple-definition

# --- Fuentes y objetos ------------------------------------------------------
C_SRCS   := $(wildcard $(SRC)/*.c)
ASM_SRCS := $(wildcard $(ASMDIR)/*.s)

C_OBJS   := $(patsubst $(SRC)/%.c,$(BUILD)/%.o,$(C_SRCS))
ASM_OBJS := $(patsubst $(ASMDIR)/%.s,$(BUILD)/%.o,$(ASM_SRCS))
OBJS     := $(C_OBJS) $(ASM_OBJS)

DEPS     := $(C_OBJS:.o=.d)
INC_DEPS := $(wildcard $(INCLUDE)/*.inc) $(wildcard $(INCLUDE)/*.h)

TARGET   := $(BUILD)/programa

# --- Reglas -----------------------------------------------------------------
.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS) | $(BUILD)
	$(LD) $(LDFLAGS) -o "$@" $^

# --- Compilación de C -------------------------------------------------------
$(BUILD)/%.o: $(SRC)/%.c | $(BUILD)
	$(CC) $(CFLAGS) -c "$<" -o "$@"

# --- Ensamblado -------------------------------------------------------------
# El ".include \"../../include/globals.inc\"" es relativo al CWD del proceso
# `as`, por eso hacemos `cd` a src/asm. La salida se escribe con ruta absoluta
# (entrecomillada para tolerar espacios en el path del proyecto).
$(BUILD)/%.o: $(ASMDIR)/%.s $(INC_DEPS) | $(BUILD)
	cd "$(ASMDIR)" && $(AS) $(ASFLAGS) -o "$(CURDIR)/$@" "$(notdir $<)"

# --- Utilidades -------------------------------------------------------------
$(BUILD):
	mkdir -p "$(BUILD)"

run: $(TARGET)
	"./$(TARGET)"

clean:
	rm -rf "$(BUILD)"

# --- Dependencias automáticas de C ------------------------------------------
-include $(DEPS)
