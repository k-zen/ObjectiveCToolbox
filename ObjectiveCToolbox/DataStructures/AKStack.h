/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2013 EvgenyKarkan
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/*
 * Copyright (c) 2014, Andreas P. Koenzen <akc at apkc.net>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#import "AKDataStructures.h"

@implementation AKStack
- (id)init
{
    self = [super init];
    if (self)
        self.stackArray = [@[] mutableCopy];
    
    return self;
}

- (AKStack *)initWithSize:(NSUInteger)size
{
    self = [super init];
    if (self) {
        if (size > 0) {
            self.stackArray   = [@[] mutableCopy];
            self.maxStackSize = size;
        }
        else {
            NSAssert(size != 0, @"Stack size must be > 0.");
        }
    }
    
    return self;
}

- (AKStack *)pop
{
    id object = [self peek];
    [self.stackArray removeLastObject];
    
    return object;
}

- (void)push:(id)object
{
    if ([self isFull] && self.maxStackSize) {
        NSLog(@"Stack is full.");
        return;
    }
    
    if (object != nil)
        [self.stackArray addObject:object];
    else
        NSAssert(object != nil, @"You can't push a NIL object into the stack.");
}

- (AKStack *)peek
{
    if ([self.stackArray count] > 0)
        return [self.stackArray lastObject];
    
    return nil;
}

- (NSInteger)size { return [self.stackArray count]; }

- (BOOL)isEmpty { return [self.stackArray count] == 0; }

- (BOOL)isFull { return ([self sizeOfStack] == self.maxStackSize) ? YES : NO; }

- (void)clear { [self.stackArray removeAllObjects]; }

- (NSArray *)allObjectsFromStack
{
    NSMutableArray *buffer = [@[] mutableCopy];
    
    for (id object in self.stackArray)
        [buffer addObject:object];
    
    return [buffer copy];
}
@end