<template>

 <div>
    <header class="header">
        <slot name="header"></slot>
    </header>
    <main class="main">
        <div :key="item.name" v-for="(item, index) in data">
            <slot :data="item"></slot>
        </div>
    </main>
    <footer class="footer">
        <slot name="footer"></slot>
    </footer>
 </div>

</template>

<script setup lang='ts'>
import {ref, reactive} from 'vue'

type names = {
    name: string,
    age: number
}

const data = reactive<names[]>([
    {
        name: "Luke",
        age: 19
    },
    {
        name: "Tebo",
        age: 20
    },
    {
        name: "Love",
        age: 21
    }
])

</script>
<style scoped lang='less'>
.header{
    height: 200px;
    background: red;
    color: #fff;
}
.main{
    height: 300px;
    background: green;
    color: #fff;
}
.footer{
    height: 200px;
    background: blue;
    color: #fff;
}

</style>