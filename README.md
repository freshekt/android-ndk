# Android NDK и OpenCV (С++) на Java Android (Windows 10)
Данный гайд расчитан на разработку в Android Studio.
0. Установить Android SDK и Android NDK
0. Открыть Android Studio -> Tools -> Android -> SDK manager
0. Открыть вкладку SDK Tools
0. Поставить CMake, LLDB. Проверить, что NDK на месте
0. В Project Structure проверить, что пути до SDK, JDK и NDK верные.

Следующий шаг нужен для удобного использования NDK:

Заходим в Preferences -> Tools -> External Tools и настраиваием такие штуки ( пути должны быть без пробелов в моем случае исходники студии пришлось в С:\AndroidStudio перенести) 
![javah](javah.png)
![ndk-build](ndk-build.png)
![ndk-build_clean](ndk-build_clean.png)

Далее в Project меняем отображение с Android на Project  и в app/src/main добавляем jni директорию как показано на картинке
![create_jni_dir](create_jni_dir.png)

Создаем класс который будет рабоать с С++
![ndkclass](ndkclass.png)

Настраиваем градл  
![configuregradle](configuregradle.png)

Не забываем  добавить android.useDeprecateNdk=true  в конец gradle.properties

Билдим проект!

Через контекстное меню  билдим заголовки нашего cpp  класса
![build_cpp_header] (build_cpp_header.png)

В папке jni cоздаем файл C++ подключаем в негосозданные заголовки и определяем  описанноые в заголовках методы
![cpp_defenition] (cpp_defenition.png)

В той же папке содаем файл Android.mk с содержимым:

```
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := ${Название Вашего класса} 
LOCAL_SRC_FILES := ${Название Вашего класса с разширением}
include $(BUILD_SHARED_LIBRARY)
```

В той же папке содаем файл Application.mk с содержимым:

```
APP_MODULES := ${Название Вашего класса}

APP_ABI := all
```

Далее черз контекстное меню на папке jni билдим ndk-build

![cpp_build](cpp_build.png)   

## Матерьялы статьи  и доп мотериалы:

[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/RmPuwdxR1qs/0.jpg)](http://www.youtube.com/watch?v=RmPuwdxR1qs)

1. [https://medium.com/@siantlords/opencv-and-android-ndk-integration-in-android-studio-883a810189e2]
2. (https://medium.com/@siantlords/opencv-and-android-ndk-integration-in-android-studio-883a810189e2)
3. [https://github.com/quanhua92/NDK_OpenCV_AndroidStudio](https://github.com/quanhua92/NDK_OpenCV_AndroidStudio)
4. [https://sriraghu.com/2017/03/11/opencv-in-android-an-introduction-part-1/](https://sriraghu.com/2017/03/11/opencv-in-android-an-introduction-part-1/)


Запускаем приложение  и радуемся)))







