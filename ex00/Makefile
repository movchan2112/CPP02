# === Config ===
NAME        := fixed
CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++98
# Для автогенерации .d-файлов зависимостей:
CPPFLAGS    := -MMD -MP

# === Sources ===
SRC         := main.cpp Fixed.cpp
OBJDIR      := obj
OBJ         := $(addprefix $(OBJDIR)/,$(SRC:.cpp=.o))
DEP         := $(OBJ:.o=.d)

# === Rules ===
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

# Паттерн-правило для сборки объектников в отдельную папку
$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# На случай, если есть файл с именем как одна из целей
.PHONY: all clean fclean re

# Подтягиваем автосгенерированные зависимости (если уже есть)
-include $(DEP)
