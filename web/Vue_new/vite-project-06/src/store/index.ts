import {defineStore} from 'pinia'
import {Names} from './store-name'

export const useTestStore = defineStore(Names.TEST, {
    state: () => {
        return {
            // 初始化
            current: 1,
            name: "Luke"
        }
    },
    // computed
    getters:{

    },
    // methods 
    actions: {

    }
})