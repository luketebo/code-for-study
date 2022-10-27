<template>

    <div class="content">
        <el-backtop :right="100" :bottom="100" />
        <div class="content-f">
            <RouterView></RouterView>
        </div>
    </div>
    <div class="footer">
        <Footer></Footer>
    </div>

</template>

<script setup lang='ts'>
import { ref, reactive } from 'vue'
import homeValue from '../../components/content/index.vue'
import Footer from '../../components/footer/index.vue'

</script>
<style scoped lang='less'>
@border: #ccc;

.content {
    height: auto;
    width: 80%;
    border: 1px solid @border;
    margin: 0 auto;
    display: flex;
    justify-content: center;
    align-items: center;

    &-f {
        width: inherit;
        justify-content: center;
        align-items: center;
    }
}

.footer {
    height: 5vw;
    width: 80%;
    margin: 0 auto;
    display: flex;
    justify-content: center;
    align-items: center;
}
</style>