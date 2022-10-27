<template>

    <div class="home">
        <header class="home-top">
            <p class="animate__animated animate__zoomInDown">与其提升自己，不如诋毁他人</p>
        </header>
        <main class="home-main">
            <div class="home-main-left">笔记</div>
            <div class="home-main-center">聊天</div>
            <div class="home-main-right">技能</div>
        </main>

    </div>

</template>

<script setup lang='ts'>
import { ref, reactive } from 'vue'
import 'animate.css'

</script>
<style scoped lang='less'>
@border: #ccc;

.home {
    height: 45vw;
    width: 100%;
    border: 1px solid @border;

    &-top {
        height: 24vw;
        width: inherit;
        display: flex;
        justify-content: center;
        align-items: center;
        border: 1px solid @border;

        p {
            font-size: 40px;
            font-weight: bold;
        }
    }

    &-main {
        display: flex;
        height: 25vw;
        flex-direction: row;
        justify-content: space-around;
        align-items: center;

        &-left {
            height: 15vw;
            width: 15vw;
            text-align: center;
            border: 1px solid @border;
        }

        &-center {
            height: 15vw;
            width: 15vw;
            text-align: center;
            border: 1px solid @border;
        }

        &-right {
            height: 15vw;
            width: 15vw;
            text-align: center;
            border: 1px solid @border;
        }
    }
}

.animate__animated.animate__zoomInDown {
    --animate-duration: 1.5s;
}
</style>