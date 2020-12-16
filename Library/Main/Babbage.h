// General non-specified header
namespace BabbageGeneral {
    int* Asize(int array[]) {
        int size = sizeof(array) / sizeof(array[0]); // Fix
        return &size;
    }
}