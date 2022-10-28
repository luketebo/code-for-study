<template>

    <div class="tagMe">
        <header class="tagMe-top">
            <a></a>
            <div>十月</div>
        </header>
        <main class="tagMe-main">
            <a>icon</a>
            <a>icon</a>
            <a>icon</a>
        </main>
        <footer class="tagMe-footer">
            <p>犹豫就会败北，所以不要犹豫</p>
        </footer>
    </div>

</template>

<script setup lang='ts'>
import {ref, reactive} from 'vue'

</script>
<style scoped lang='less'>
@border: #ccc;

.tagMe {
    height: 10vw;
    width: 80%;
    border-radius: 3px;
    border: 1px solid @border;
    margin: 15px 0;

    &-top {
        display: flex;
        // padding-left: 10%;
        padding: 5% 0 5% 10%;
        a {
            width: 3vw;
            height: 3vw;
            margin-right: 5%;
            border: 1px solid @border;
            background-image: url(../../assets/index.jpeg);
            background-size: cover;
        }
        div {
            width: 3vw;
            height: 3vw;
            border: 1px solid @border;
            display: flex;
            justify-content: center;
            align-items: center;
            font-size: 25px;
            font-weight: bold;
        }
    }

    &-main {
        padding: 5% 0 5% 10%;
        a {
            margin: 0 15% 0 0;
        }
        
    }

    &-footer {
        padding: 5% 0 5% 10%;

    }
}

</style>