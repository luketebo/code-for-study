<template>
    <el-affix>
        <nav class="header">
            <a class="header-left" style="text-decoration: none" href="javascript: void(0)"> 
                <div class="img_"></div>
                <span style="font-weight: bold; font-size: 25px;">
                    十月
                </span>
            </a>
            <div class="header-right">
                <div class="flex-grow" />
                <div class="header-right-search">
                    <el-input v-model="input1" :prefix-icon="Search" />
                </div>
                <div class="header-right-bar">
                    <rightBar></rightBar>
                </div>
            </div>
        </nav>
    </el-affix>
</template>

<script setup lang='ts'>
import { ref, reactive } from 'vue'
import rightBar from '../../components/header/right-bar.vue'
import { Search } from "@element-plus/icons-vue"

const input1 = ref('')


</script>
<style scoped lang='less'>
@border: #ccc;

.img_ {
    background-image: url(../../assets/index.jpeg);
    background-size: cover;
    height: 30px;
    width: 30px;
    margin-right: 15px;
}

.header {
    left: 0;
    top: 0;
    width: 100%;
    height: 2.5vw;
    background-color: white;
    // position: fixed;
    // filter: blur(6px);
    display: flex;
    flex-wrap: wrap;
    border-bottom: 1px solid @border;
    flex-direction: column;
    justify-content: space-between;

    &-left {
        height: inherit;
        width: 15%;
        display: flex;
        justify-content: center;
        align-items: center;
    }


    &-right {
        height: inherit;
        display: flex;
        justify-content: center;
        align-items: center;

        &-search {
            // height: 5vh;
            height: inherit;
            padding-right: 15px;
            display: flex;
            justify-content: center;
            align-items: center;
        }

        &-bar {
            height: inherit;
            display: flex;
            justify-content: center;
            align-items: center;
        }
    }
}

.flex-grow {
    flex-grow: 1;
}
</style>