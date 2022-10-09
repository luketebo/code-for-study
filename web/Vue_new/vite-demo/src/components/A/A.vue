<template>

 <div class="dialog">
    <header class="header">
        <div>
            {{ title }}
        </div>
    </header>
    <main class="main">
        {{ content }}
    </main>
    <footer class="footer">
        <button @click="fuck(true)" class="footer-but">Cancel</button>
        <button @click="fuck(false)" class="footer-but">Sure</button>
    </footer>

 </div>

</template>

<script setup lang='ts'>
import {ref, reactive} from 'vue'

const content = ref("我是内容")
const title = ref("我是弹窗")

const fuck = (type:boolean) => {
    if (type) {
        content.value = "我是你爹"
    } else {
        title.value = "good sum"
    }
}

</script>
<style scoped lang='less'>
.dialog{
    height: 300px;
    border: 1px solid black;
    background-color: black;
    width: 300px;
    display: flex;
    flex-direction: column;
    position: absolute;
    left: 50%;
    top: 50%;
    margin-left: -200px;
    margin-top: -200px;
}
.header{
    color: white;
    border-bottom: 1px solid #ccc;
    height: 25px;
}
.main{
    color: white;
    flex: 1;
    border-bottom: 1px solid #ccc;
    height: 250px;
}
.footer{
    display: flex;
    padding: 10px;
    justify-content: end;
    &-but{
        border-radius: 3px;
        background-color: skyblue;
        margin-right: 10px;
    }
}

</style>