<template>

    <div class="home">
        <header class="home-top">
            <p class="animate__animated animate__zoomInDown note">与其提升自己，不如诋毁他人</p>
            <p class="animate__animated animate__zoomInDown note">&nbsp&nbsp我是大厦B</p>
        </header>
        <main class="home-main">
            <div class="home-main-left">
                <div class="home-main-left-icon"></div>
                <p>笔记</p>
            </div>
            <div class="home-main-center">
                <div class="home-main-center-icon"></div>
                <p>项目</p>
            </div>
            <div class="home-main-right">
                <div class="home-main-right-icon"></div>
                <p>技能</p>
            </div>
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
    height: 49vw;
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
            display: flex;
            flex-direction: column;
            justify-content: center;
            align-items: center;

            &-icon {
                border: 1px solid @border;
                width: 55%;
                height: 55%;
                background-size: cover;
                background-image: url(../../assets/icon/renwuguanli.png);
            }

            p {
                font-size: 25px;
                font-weight: bold;
            }
        }

        &-center {
            height: 15vw;
            width: 15vw;
            text-align: center;
            border: 1px solid @border;
            display: flex;
            flex-direction: column;
            justify-content: center;
            align-items: center;

            &-icon {
                border: 1px solid @border;
                width: 55%;
                height: 55%;
                background-size: cover;
                background-image: url(../../assets/icon/shounahe.png);
            }

            p {
                font-size: 25px;
                font-weight: bold;
            }
        }

        &-right {
            height: 15vw;
            width: 15vw;
            text-align: center;
            border: 1px solid @border;
            display: flex;
            flex-direction: column;
            justify-content: center;
            align-items: center;

            &-icon {
                border: 1px solid @border;
                width: 55%;
                height: 55%;
                background-size: cover;
                background-image: url(../../assets/icon/xunzhang.png);
            }
            
            p {
                font-size: 25px;
                font-weight: bold;
            }
        }
    }
}

.animate__animated.animate__zoomInDown {
    --animate-duration: 1.5s;
}
</style>

