<template>
    <div class="content">
        <button @click="change"></button>
        <transition-group move-class="mmm" class="wraps" tag="div">
            <div class="item" :key="item.id" v-for="item in list">
                {{ item.number }}
            </div>
        </transition-group>
    </div>
</template>

<script setup lang='ts'>
import {ref, reactive} from 'vue'
import _ from 'lodash'

const change = () => {
    list.value = _.shuffle(list.value)
}


let list = ref(Array.apply(null, { length: 81 } as number[]).map((_, index) => {
    return {
        id: index,
        number: (index % 9) + 1
    }
}))


</script>
<style scoped lang='less'>


.wraps {
    display: flex;
    flex-wrap: wrap;
    width: calc(25px * 10 + 9px);
    .items {
        width: 25px;
        height: 25px;
        border: 1px solid #ccc;
        display: flex;
        justify-content: center;
        align-items: center;
    }
}

.mmm {
    transition: all 1s ease;
}
</style>

