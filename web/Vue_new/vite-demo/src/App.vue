<template>

    <div>
       reactive {{ obj_}}
       shallowReactive {{ obj }}
    </div>
    <button @click="edit">edit</button>
    <button @click="edit_">edit_</button>
    <button @click="_edit_">_edit_</button>


</template>

<script setup lang='ts'>
import { ref, reactive, readonly, shallowReactive } from 'vue'
const obj_ = reactive({name: "Luke"})

const obj:any = shallowReactive({
    foo: {
        bar: {
            num: 1
        }
    }
})

const edit = () => {
    obj.foo.bar.num = 333
    console.log(obj)
}

const edit_ = () => {
    obj.foo = {name: "Luke"}
    console.log(edit_)
}

const _edit_ = () => {
    obj_.name = "Vue"
    obj.foo.bar.num =  "what"
    console.log(obj)
}

</script>
<style scoped>

</style> 