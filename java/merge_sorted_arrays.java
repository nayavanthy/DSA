// Online Java Compiler
// Use this editor to write, compile and run your Java code online

//merge 2 sorted arrays

class Main {
    private static int[] merge_sorted_array(int[] a, int size_a, int[] b, int size_b){
        int[] ret = new int[size_a + size_b];
        int i = 0, j = 0;
        
        while(i<size_a && j<size_b){
            if(a[i] < b[j]){
                ret[i+j] = a[i];
                i++;
            }else{
                ret[i+j] = b[j];
                j++;
            }
        }
        
        while(i<size_a){
            ret[i+j] = a[i];
            i++;
        }
        
        while(j<size_b){
            ret[i+j] = b[j];
            j++;
        }
        
        return ret;
    }
    
    public static void main(String[] args) {
        int[] a = { 1, 2, 3, 4, 4};
        int[] b = { 2, 4, 5, 5};
        int size_a = 5;
        int size_b = 4;
        
        int[] c;
        
        c = merge_sorted_array(a, size_a, b, size_b);
        
        for(int i : c){
            System.out.println(i);
        }
    }
}