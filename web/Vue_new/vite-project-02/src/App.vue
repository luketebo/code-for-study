<template>

    

</template>

<script setup lang='ts'>
import { ref, reactive, getCurrentInstance} from 'vue'


const instance = getCurrentInstance()

instance?.proxy?.$loading.show()
</script>
<style scoped lang='less'>

</style>