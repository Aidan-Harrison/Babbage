// General non-specified header

// Function Prototypes
// REFER TO UE4 FOR BETTER UNDERSTANDING OF IMPLEMENTATION
// CANNOT HAVE TEMPLATES IN THIS FILE. SPECIFIED ONLY
namespace BabbageGeneral {
        int* Asize(int array[]) {
            int size = sizeof(array) / sizeof(array[0]); // Fix
            return &size;
        }
}