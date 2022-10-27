<template>

    <nav class="header">

        <a class="header-left"> icon
            <img />
            <span>
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

</template>

<script setup lang='ts'>
import { ref, reactive } from 'vue'
import rightBar from './right-bar.vue'
import { Search } from "@element-plus/icons-vue"

const input1 = ref('')


</script>
<style scoped lang='less'>
@border: #ccc;

.header {
    left: 0;
    top: 0;
    width: 100%;
    height: 15vh;
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