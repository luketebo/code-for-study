<template>
    <div class="content">

            <button @click="ADD">ADD</button>
            <button @click="POP">POP</button>
        <div class="wraps">
            <transition-group
            leave-active-class="animate_animated animate__wobble" 
            enter-active-class="animate__animated animate__flash">
                <div class="wraps-item" :key="item" v-for="item in list">
                    {{item}}
                </div>
            </transition-group>
        </div>
    </div>

</template>

<script setup lang='ts'>
import { ref, reactive, markRaw, defineAsyncComponent } from 'vue'
import 'animate.css'

const list = reactive<number[]>([1, 2, 3, 4, 5])

const ADD = () => {
    list.push(list.length + 1)
}
const POP = () => {
    list.pop()
}

</script>
<style scoped lang='less'>
.wraps {
    display: flex;
    flex-wrap: wrap;
    word-break: break-all;
    border: 1px solid #ccc;
    &-item{
        margin: 10px;
    }

}

.tab {
    display: flex;

    .active {
        background: skyblue;
        color: #fff;
    }

    div {
        margin: 10px;
        border: 1px solid #ccc;

    }
}
</style>