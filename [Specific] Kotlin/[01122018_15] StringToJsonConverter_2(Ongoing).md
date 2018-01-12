Implementation is not done yet. It's ongoing practice.

```

class JsonConverter(val originalJsonString: String, var depth: Int = 1)
{
    companion object {
        const val KEY = 0
        const val VALUE = 1
    }

    var currentJsonString: String = originalJsonString
    var prevJsonString: String = originalJsonString
    var curlyBraceStack: MutableList<String> = mutableListOf<String>()
    var curlyCnt: Int = 0
    var sourceMap: MutableMap<String, Any> = mutableMapOf<String, Any>()
    var key: String = ""
    var value: String = ""
    var flgObj: Boolean = false
    var currentBracketStatus: String = "First"
    var prevBracketStatus: String = ""
    var flgContinue = false
    var parentKey: String = ""

    fun convertJsonToObect()
    {
        if (isJson()) {
            makeSourceArrayFromString()
        }
        //makeObjectFromSourceArray()
    }

    fun makeSourceArrayFromString()
    {
        var cnt = 0
        while (this.depth != 0) {
            if (cnt++ == 12) {
                break
            }

            setKeyValuePair(this.currentBracketStatus)
            setBracketStatus(this.value)

            if (this.flgContinue) {
                continue
            }

            when (checkType()) {
                "String" -> println("This value is String")
                "Integer"-> println("This value is Integer")
                "Boolean"-> println("This value is Boolean")
                "Object" -> println("This value is Object")
                "Array"  -> println("This value is Array")
            }
            this.flgObj = false
        }
        //println(this.curlyBraceStack.get(0))
        //println(this.curlyBraceStack.get(1))
    }

    fun setBracketStatus(valueString: String)
    {
        if (valueString.contains('{')) {
            this.currentBracketStatus = "CurlyOpen"
            this.flgContinue = true
            this.depth++
        } else if (valueString.contains('}')) {
            this.currentBracketStatus = "CurlyClose"
            this.depth--
        } else if (valueString.contains('[')) {
            this.currentBracketStatus = "SquareOpen"
            this.flgContinue = true
        } else if (valueString.contains(']')) {
            this.currentBracketStatus = "SquareClose"
            this.flgContinue = false
        } else {
            this.currentBracketStatus = "Ongoing"
        }
        /*} else if (this.currentBracketStatus.equals("SquareOpen")) {
            this.currentBracketStatus = "Ongoing"
        } else if (this.currentBracketStatus.equals("CurlyOpen")) {
            this.currentBracketStatus = "Ongoing"
        //} else if (this.currentBracketStatus.equals("SquareClose") || this.currentBracketStatus.equals("CurlyClose")) {
        } else {
            this.currentBracketStatus = this.prevBracketStatus
        }*/
    }

    fun setKeyValuePair(bracketStatus: String)
    {
        var temp: String = this.currentJsonString
        when (bracketStatus) {
            "First" -> {
                temp = temp.substring(temp.indexOfFirst { it == '"' }, temp.lastIndex)
                this.currentJsonString = temp
                this.curlyBraceStack.add(curlyBraceStack.count(), "{")
                this.prevJsonString = this.currentJsonString
                var commaIndex: Int = this.currentJsonString.indexOf(',')
                var keyValueString: String = this.currentJsonString.substring(0, commaIndex)
                this.currentJsonString = this.currentJsonString.substring(commaIndex+1, this.currentJsonString.lastIndex)
                var stringList: List<String> = keyValueString.split(":")
                this.key = stringList.get(KEY).trim()
                this.value = stringList.get(VALUE).trim()
            }
            "CurlyOpen"  -> {
                println("***Curly brace is opened!***")
                this.currentJsonString = this.prevJsonString
                this.curlyBraceStack.add(this.curlyCnt++, this.key.trim('"'))
                temp = temp.substring(temp.indexOfFirst { it == '{' }+1, temp.lastIndex)
                this.currentJsonString = temp
                this.value = ""
            }
            "CurlyClose" -> {
                println("***Curly brace is closed!***")

            }
            "SquareOpen" -> {
                println("***Square braket is oped!***")

            }
            "SquareClose"-> {
                println("***Square braket is closed!***")

            }
            "Ongoing"    -> {
                this.prevJsonString = this.currentJsonString
                var commaIndex: Int = this.currentJsonString.indexOf(',')
                var keyValueString: String = this.currentJsonString.substring(0, commaIndex)
                this.currentJsonString = this.currentJsonString.substring(commaIndex+1, this.currentJsonString.lastIndex)
                var stringList: List<String> = keyValueString.split(":")
                this.key = stringList.get(KEY).trim()
                this.value = stringList.get(VALUE).trim()
            }
        }
        println("(1)status: ${this.currentBracketStatus}")
        println("(1)key: ${this.key} value: ${this.value}")
        println("(3)depth: ${this.depth}")
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
        val value: String = this.value
        if (value.first() == '"') {
            return "String"
        } else if (value.toIntOrNull() != null) {
            return "Integer"
        } else if (value.toBoolean() != null) {
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