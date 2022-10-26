<template>

    <nav class="header">
        <a class="header-left"> icon
            <img />
            <span>
                十月
            </span>
        </a>
        <div class="header-right">
            <el-row>
                <el-col :span="6"></el-col>
                <el-col :span="6">
                    <div class="header-right-search">
                        <el-input v-model="input1" :prefix-icon="Search" />
                    </div>
                </el-col>
                <el-col :span="12">
                    <div class="header-right-bar">
                        <rightBar></rightBar>
                    </div>
                </el-col>
            </el-row>
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
    height: 10vh;
    display: flex;
    flex-wrap: wrap;
    flex-direction: column;
    justify-content: space-between;

    &-left {
        height: inherit;
        width: 15%;
        // padding-top: 15px;
        // padding-left: 5%;
    }


    &-right {
        display: flex;
        padding-top: 15px;
        // justify-content: space-around;
        // padding-right: 15%;
        margin-left: 11.3%;

        &-search {
            height: 5vh;
            padding-right: 15px;
            display: flex;
            justify-content: center;
            align-items: center;
            // margin-left: 15%;
            // padding-right: 15%;
            // margin-right: 15%;
        }

        &-bar {
            height: 5vh;
            display: flex;
            justify-content: center;
            align-items: center;

        }
    }
}
</style>