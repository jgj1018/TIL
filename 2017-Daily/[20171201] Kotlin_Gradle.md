[ref1](https://kotlinlang.org/docs/reference/using-gradle.html)

# Inside build.Gradle


The version of Kotlin to use is usually defined as the kotlin_version property:

```
buildscript {
    ext.kotlin_version = '1.2.0'

    repositories {
        mavenCentral()
    }

    dependencies {
        classpath "org.jetbrains.kotlin:kotlin-gradle-plugin:$kotlin_version"
    }
}
```

To target the JVM, the Kotlin plugin needs to be applied:

```
apply plugin: "kotlin"
```

Kotlin sources can be mixed with Java sources in the same folder, or in different folders. The default convention is using different folders:

```
project
    - src
        - main (root)
            - kotlin
            - java
```

The corresponding sourceSets property should be updated if not using the default convention:

```
sourceSets {
    main.kotlin.srcDirs += 'src/main/myKotlin'
    main.java.srcDirs += 'src/main/myJava'
}
```

# Configuring Dependencies 

I need to add a dependency on the Kotlin standard library:

```
repositories {
    mavenCentral()
}

dependencies {
    compile "org.jetbrains.kotlin:kotlin-stdlib"
}
```

If my project uses Kotlin reflection or testing facilities, I need to add the corresponding dependencies as well:

```
compile "org.jetbrains.kotlin:kotlin-reflect"
testCompile "org.jetbrains.kotlin:kotlin-test"
testCompile "org.jetbrains.kotlin:kotlin-test-junit"
```