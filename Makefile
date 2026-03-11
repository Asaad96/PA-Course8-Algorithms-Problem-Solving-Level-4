# اسم البرنامج النهائي
TARGET = DayOfBirth

# ملفات السورس (المصادر)
SRCS = DayOfBirth.cpp my_library.cpp

# ملفات الـ Object (سيتم إنشاؤها تلقائياً)
OBJS = $(SRCS:.cpp=.o)

# الإعدادات التي كنت تستخدمها في سطر الأوامر
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -pedantic -g -fsanitize=address,undefined

# القاعدة الأساسية لبناء البرنامج
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# قاعدة لتحويل كل ملف .cpp إلى .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# تنظيف الملفات المؤقتة
clean:
	rm -f $(OBJS) $(TARGET)CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -pedantic -g -fsanitize=address,undefined

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

main: main.o math.o
	$(CXX) $(CXXFLAGS) main.o math.o -o main

main.o: main.cpp math.h
	$(CXX) $(CXXFLAGS) -c main.cpp

math.o: math.cpp math.h
	$(CXX) $(CXXFLAGS) -c math.cpp

clean:
	rm -f *.o main
