Implementation is not done yet. It's ongoing practice.


```

class JsonConverter2(val originalJsonString: String, var depth: Int = 1)
{
    companion object {
        const val KEY = 0
        const val VALUE = 1
    }

    var sourceMap: MutableMap<String, Any> = mutableMapOf<String, Any>()
    var flgContinue = false
    var flgArray = false
    var currentStatus: String = "First"
    var remainingJsonText: String = originalJsonString
    var textSegment: String = ""
    var isLastSegment: Boolean = false
    var commaIndex: Int = 0
    var parentKey: String = ""
    var key: String = ""
    var value: String = ""
    var BracketStack: MutableList<Char> = mutableListOf<Char>()

    fun convertJsonToObect()
    {
        if (isJson()) {
            makeSourceArrayFromString()
        }
        //makeObjectFromSourceArray()
    }

    fun makeSourceArrayFromString()
    {
        while (remainingJsonText.trim().isNotBlank()) {
            checkCurrentStatus()
            beforeSettingText()
            setTextSegment()
            splitTextSegment()
            afterSettingText()
            if (this.flgContinue) {
                println("(3)*******Continued*******")
            } else {
                when (checkType()) {
                    "String" -> println("(4)This value is String")
                    "Integer"-> println("(4)This value is Integer")
                    "Boolean"-> println("(4)This value is Boolean")
                    "Object" -> println("(4)This value is Object")
                }
            }
            println("(5)bracket: ${this.BracketStack}")
        }
    }

    fun checkCurrentStatus()
    {
        if (this.BracketStack.isNotEmpty()) {
            var checkChar:Char = BracketStack.get(BracketStack.size-1)

            when (checkChar) {
                '{' -> {
                    currentStatus = "Object"
                    //object
                }
                '[' -> {
                    currentStatus = "Array"
                    //array
                }
                'N'  -> {
                    currentStatus = "Normal"
                    //normal
                }
            }
            flgContinue = false
        }
    }

    fun beforeSettingText()
    {
        when (this.currentStatus) {
            "First" -> {
                var temp: String = remainingJsonText
                temp = temp.substring(temp.indexOfFirst { it == '"' }, temp.lastIndex+1).trim()
                remainingJsonText = temp
                BracketStack.add(BracketStack.count(), 'N')
            }
            "Array" -> {
                flgArray = true
            }
        }

        var firstChar:Char = remainingJsonText.first()

        /*while (firstChar == '}' || firstChar == ']') {
            remainingJsonText = remainingJsonText.substring(1, remainingJsonText.lastIndex+1)
            firstChar = remainingJsonText.first()
        }

        while (firstChar == '{' || firstChar == '[') {
            remainingJsonText = remainingJsonText.substring(1, remainingJsonText.lastIndex+1)
            firstChar = remainingJsonText.first()
        }*/
    }

    fun setTextSegment()
    {
        isLastSegment = !(remainingJsonText.contains(','))
        if (isLastSegment) {
            textSegment = remainingJsonText.substring(0, remainingJsonText.lastIndex+1)
        } else {
            commaIndex = remainingJsonText.indexOf(',')
            textSegment = remainingJsonText.substring(0, this.commaIndex)
        }
    }

    fun splitTextSegment()
    {
        if (!this.flgArray) {
            var stringList: List<String> = this.textSegment.split(":")
            key = stringList.get(KEY).trim()
            value = stringList.get(VALUE).trim()
        } else {
            value = this.textSegment.trim()
        }

        println("(2)key: ${this.key} value: ${this.value}")
    }

    fun afterSettingText()
    {
        if (value.contains('[')) {
            commaIndex = remainingJsonText.indexOf('[')
            BracketStack.add(BracketStack.count(), '[')
            flgContinue = true
        } else if (value.contains('{')) {
            commaIndex = remainingJsonText.indexOf('{')
            BracketStack.add(BracketStack.count(), '{')
            flgContinue = true
        } else if (value.contains('}') || value.contains(']')) {
            value.forEach { if(it == '}' || it == ']') {
                    BracketStack.removeAt(BracketStack.size-1)
                }
            }
            flgContinue = true
        }

        if (!isLastSegment) {
            remainingJsonText = remainingJsonText.substring(commaIndex+1, remainingJsonText.lastIndex+1)
        }
    }

    /**
     * This method is to set type for each value based on Kotlin type.
     * Each Json data type will be converted as below
     *
     * Json   -> Kotlin
     * =================
     * Number -> Integer
     * String -> String
     * Object -> Object TODO
     * Array  -> Array
     * Boolean-> Boolean
     * Null   -> Null TODO
     *
     */
    fun checkType(): String
    {
        val value: String = value
        if (value.isNotBlank() && value.first() == '"') {
            return "String"
        } else if (value.toIntOrNull() != null) {
            return "Integer"
        } else if (value.toBoolean()) {
            return "Boolean"
        }
        return ""
    }

    /**
     * This method checks two things.
     * (1) The number of curly brace have to be even number.
     * (2) The string have to be started and ended with curly brace.
     */
    fun isJson(): Boolean
    {

        return true
    }

    /**
     * This method is to check if any specific string contains backslash for escaping.
     */
    fun isEscaped()
    {

    }

    fun makeObjectFromSourceArray()
    {

    }
}
```