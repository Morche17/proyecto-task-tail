BASE_DIR     := .
SRC_DIR      := src
CPP_FILES    := $(wildcard $(SRC_DIR)/*.cpp)
STATIC_LIBS  := $(wildcard external/*.a)
LIBS         := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 
BUILD_DIR    := build
TARGET       := app
CFLAGS       := -Wall -IInclude/

# Genera nombres de archivos de objeto correspondientes a los archivos .cpp
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(CPP_FILES))


# Objetivo predeterminado: compilar y guardar en el directorio de destino
all: $(TARGET)

# Regla de construcción para los archivos de objeto
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CFLAGS) -c -o $@ $<

# Regla de construcción para el programa final
$(TARGET): $(OBJ_FILES)
	g++ $(CFLAGS) -o $@ $^ $(STATIC_LIBS)	


clean:
	rm -rf $(BUILD_DIR)/* $(PROGRAM_NAME)
